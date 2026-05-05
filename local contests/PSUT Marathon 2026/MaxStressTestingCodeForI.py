import random
import multiprocessing
import time
import os

def get_next_state(a):
    n = len(a)
    
    # Optimized prefix min
    p_min = a[:]
    for i in range(1, n):
        if p_min[i-1] < p_min[i]: 
            p_min[i] = p_min[i-1]
            
    # Optimized suffix max
    s_max = a[:]
    for i in range(n-2, -1, -1):
        if s_max[i+1] > s_max[i]: 
            s_max[i] = s_max[i+1]
            
    return [p_min[i] ^ s_max[i] for i in range(n)]

def simulate_array(test_arr):
    steps = 0
    curr = test_arr
    
    # Fast check for all same elements
    while len(set(curr)) > 1:
        curr = get_next_state(curr)
        steps += 1
        
    return steps, test_arr

def worker_task(iterations):
    local_max_k = 0
    best_array = []
    
    for _ in range(iterations):
        n = random.randint(2, 100)
        # Biasing some arrays to be strictly decreasing or increasing 
        # can sometimes delay the convergence.
        test_arr = [random.randint(0, 2**60) for _ in range(n)]
        
        steps, _ = simulate_array(test_arr)
        
        if steps > local_max_k:
            local_max_k = steps
            best_array = test_arr
            
    return local_max_k, best_array

if __name__ == '__main__':
    TOTAL_ITERATIONS = 10_000_000
    CORES = multiprocessing.cpu_count()
    ITERATIONS_PER_CORE = TOTAL_ITERATIONS // CORES

    print(f"Starting search across {CORES} cores for {TOTAL_ITERATIONS} iterations...")
    start_time = time.time()

    # Create a pool of workers
    with multiprocessing.Pool(CORES) as pool:
        results = pool.map(worker_task, [ITERATIONS_PER_CORE] * CORES)

    # Find the global maximum from all workers
    global_max_k = 0
    global_best_array = []
    
    for k, arr in results:
        if k > global_max_k:
            global_max_k = k
            global_best_array = arr

    end_time = time.time()
    
    print(f"Search completed in {end_time - start_time:.2f} seconds.")
    print(f"Global Max K Found: {global_max_k}")
    
    # Save to file in standard CP format (T, N, Array)
    filename = "worst_case.txt"
    with open(filename, "w") as f:
        f.write("1\n") # T = 1 testcase
        f.write(f"{len(global_best_array)}\n") # N
        f.write(" ".join(map(str, global_best_array)) + "\n") # The array
        
    print(f"Test case successfully saved to {os.path.abspath(filename)}")