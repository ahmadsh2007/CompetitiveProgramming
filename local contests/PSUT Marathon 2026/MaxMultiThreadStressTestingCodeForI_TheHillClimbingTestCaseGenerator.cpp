// g++ -O3 -pthread .\MaxMultiThreadStressTestingCodeForI_TheHillClimbingTestCaseGenerator.cpp -o .\MaxMultiThreadStressTestingCodeForI_TheHillClimbingTestCaseGenerator

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>
#include <atomic>
#include <fstream>
#include <iomanip>

using namespace std;

const int N = 150;
const long long TOTAL_GENERATIONS = 30000000000LL; // 30 Billion for ~3 hours
const int STAGNATION_LIMIT = 50000;

// Atomic variables to track global progress and bests across all threads
atomic<long long> global_completed_gens(0);
atomic<int> global_best_k(0);

// Pre-allocated buffers to prevent dynamic memory allocation overhead
struct ThreadBuffers {
    uint64_t p_min[N];
    uint64_t s_max[N];
    uint64_t curr[N];
};

int get_k(const uint64_t* start_arr, ThreadBuffers& b) {
    for (int i = 0; i < N; ++i) b.curr[i] = start_arr[i];
    
    int steps = 0;
    while (true) {
        bool all_same = true;
        for (int i = 1; i < N; ++i) {
            if (b.curr[i] != b.curr[0]) {
                all_same = false;
                break;
            }
        }
        if (all_same) break;

        b.p_min[0] = b.curr[0];
        for (int i = 1; i < N; ++i) {
            b.p_min[i] = min(b.p_min[i - 1], b.curr[i]);
        }

        b.s_max[N - 1] = b.curr[N - 1];
        for (int i = N - 2; i >= 0; --i) {
            b.s_max[i] = max(b.s_max[i + 1], b.curr[i]);
        }

        for (int i = 0; i < N; ++i) {
            b.curr[i] = b.p_min[i] ^ b.s_max[i];
        }
        steps++;
    }
    return steps;
}

void mutate(uint64_t* arr, mt19937_64& rng) {
    uniform_real_distribution<double> chance(0.0, 1.0);
    uniform_int_distribution<int> idx_dist(0, N - 1);
    
    double type = chance(rng);
    int idx = idx_dist(rng);

    if (type < 0.4) {
        int bit = uniform_int_distribution<int>(0, 60)(rng);
        arr[idx] ^= (1ULL << bit);
    } else if (type < 0.6) {
        if (idx < N - 1) swap(arr[idx], arr[idx + 1]);
    } else if (type < 0.7) {
        if (uniform_int_distribution<int>(0, 1)(rng) == 0) arr[idx] = 0;
        else arr[idx] = uniform_int_distribution<uint64_t>(0, (1ULL << 60) - 1)(rng);
    } else if (type < 0.85) {
        uint64_t mask = uniform_int_distribution<uint64_t>(1, 1024)(rng);
        arr[idx] ^= mask;
    } else {
        int max_len = N - idx;
        if (max_len >= 2) {
            int limit = min(15, max_len);
            int length = uniform_int_distribution<int>(2, limit)(rng);
            reverse(arr + idx, arr + idx + length);
        }
    }
}

void worker_search(int worker_id, long long generations, int& out_k, vector<uint64_t>& out_arr) {
    mt19937_64 rng(random_device{}() + worker_id);
    ThreadBuffers b;
    
    vector<uint64_t> current_arr(N);
    for (int i = 0; i < N; ++i) {
        current_arr[i] = (i % 2 == 0) ? (1ULL << (60 - i / 2)) : 0;
    }
    
    int current_k = get_k(current_arr.data(), b);
    int worker_best_k = current_k;
    vector<uint64_t> worker_best_arr = current_arr;
    
    int stagnation_counter = 0;
    vector<uint64_t> candidate_arr(N);

    for (long long gen = 0; gen < generations; ++gen) {
        candidate_arr = current_arr;
        mutate(candidate_arr.data(), rng);
        int candidate_k = get_k(candidate_arr.data(), b);

        if (candidate_k >= current_k) {
            current_arr = candidate_arr;
            current_k = candidate_k;
            
            if (current_k > worker_best_k) {
                worker_best_k = current_k;
                worker_best_arr = current_arr;
                stagnation_counter = 0;
                
                // Update global atomic best for live tracking
                int current_global = global_best_k.load();
                while (worker_best_k > current_global && 
                       !global_best_k.compare_exchange_weak(current_global, worker_best_k)) {
                }
            } else {
                stagnation_counter++;
            }
        } else {
            stagnation_counter++;
        }

        // The Nuke
        if (stagnation_counter > STAGNATION_LIMIT) {
            uniform_int_distribution<uint64_t> big_dist(0, (1ULL << 60) - 1);
            for (int i = 0; i < N; ++i) current_arr[i] = big_dist(rng);
            current_k = get_k(current_arr.data(), b);
            stagnation_counter = 0;
        }
        
        // Progress tracking (Update every 5 million per thread to avoid lock contention)
        if (gen % 5000000 == 0) {
            global_completed_gens += 5000000;
        }
    }
    
    out_k = worker_best_k;
    out_arr = worker_best_arr;
}

// Progress Monitor Thread
void monitor_progress(chrono::time_point<chrono::high_resolution_clock> start_time) {
    while (true) {
        this_thread::sleep_for(chrono::seconds(10));
        long long completed = global_completed_gens.load();
        if (completed >= TOTAL_GENERATIONS) break;
        
        auto now = chrono::high_resolution_clock::now();
        double elapsed = chrono::duration<double>(now - start_time).count();
        double speed = completed / elapsed / 1000000.0; // Millions per sec
        double percent = (double)completed / TOTAL_GENERATIONS * 100.0;
        
        cout << fixed << setprecision(2);
        cout << "[Progress: " << percent << "%] " 
             << "Generations: " << completed / 1000000 << "M / " << TOTAL_GENERATIONS / 1000000 << "M "
             << "| Speed: " << speed << " M/sec "
             << "| Current Peak K: " << global_best_k.load() << endl;
    }
}

int main() {
    int cores = thread::hardware_concurrency();
    long long gens_per_core = TOTAL_GENERATIONS / cores;
    
    cout << "Starting Multi-Threaded C++ Hill Climbing..." << endl;
    cout << "Targeting " << TOTAL_GENERATIONS << " mutations across " << cores << " cores." << endl;
    cout << "Estimated Runtime: ~3 Hours. Progress updates every 10 seconds." << endl << endl;

    auto start_time = chrono::high_resolution_clock::now();
    
    vector<thread> threads;
    vector<int> out_k(cores);
    vector<vector<uint64_t>> out_arr(cores);
    
    // Launch worker threads
    for (int i = 0; i < cores; ++i) {
        threads.emplace_back(worker_search, i, gens_per_core, ref(out_k[i]), ref(out_arr[i]));
    }
    
    // Launch monitor thread
    thread monitor(monitor_progress, start_time);
    
    // Join workers
    for (auto& t : threads) {
        t.join();
    }
    
    // Ensure terminal generation counts match up, then join monitor
    global_completed_gens = TOTAL_GENERATIONS;
    monitor.join();

    // Aggregate
    int absolute_peak_k = 0;
    vector<uint64_t> best_array;
    for (int i = 0; i < cores; ++i) {
        if (out_k[i] > absolute_peak_k) {
            absolute_peak_k = out_k[i];
            best_array = out_arr[i];
        }
    }

    auto end_time = chrono::high_resolution_clock::now();
    cout << "\nEvolution complete in " << chrono::duration<double>(end_time - start_time).count() << " seconds." << endl;
    cout << "==== ABSOLUTE PEAK K REACHED: " << absolute_peak_k << " ====" << endl;

    ofstream out("worst_case.txt");
    out << "1\n" << N << "\n";
    for (int i = 0; i < N; ++i) out << best_array[i] << (i == N - 1 ? "" : " ");
    out << "\n";
    
    cout << "Test case successfully written to worst_case.txt" << endl;
    return 0;
}