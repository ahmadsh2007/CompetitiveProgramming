import random
import time
import os
import multiprocessing

def get_next_state(a):
    n = len(a)
    p_min = a[:]
    for i in range(1, n):
        if p_min[i-1] < p_min[i]: p_min[i] = p_min[i-1]
            
    s_max = a[:]
    for i in range(n-2, -1, -1):
        if s_max[i+1] > s_max[i]: s_max[i] = s_max[i+1]
            
    return [p_min[i] ^ s_max[i] for i in range(n)]

def get_k(test_arr):
    steps = 0
    curr = test_arr
    # Fast check for all same elements using sets
    while len(set(curr)) > 1:
        curr = get_next_state(curr)
        steps += 1
    return steps

def mutate(arr):
    """Mutate the array to explore neighboring states."""
    new_arr = arr[:]
    n = len(new_arr)
    mutation_type = random.randint(1, 4)
    
    idx = random.randint(0, n - 1)
    
    if mutation_type == 1:
        # Bit flip at a random position
        bit = random.randint(0, 60)
        new_arr[idx] ^= (1 << bit)
    elif mutation_type == 2:
        # Swap two adjacent elements (disrupts monotonic sequences)
        if idx < n - 1:
            new_arr[idx], new_arr[idx+1] = new_arr[idx+1], new_arr[idx]
    elif mutation_type == 3:
        # Replace with a massive number
        new_arr[idx] = random.randint(0, 2**60)
    elif mutation_type == 4:
        # Replace with 0 (forces min drops)
        new_arr[idx] = 0
        
    return new_arr

def worker_hill_climb(worker_id, generations, n_size):
    """The function each CPU core will run independently."""
    # Seed using OS randomness so workers don't mirror each other
    random.seed(os.urandom(8))
    
    # Start with the smart anti-heuristic guess
    best_arr = [(1 << (60 - i//2)) if i % 2 == 0 else 0 for i in range(n_size)]
    
    # Give each worker a slight random kick so they explore different "mountains"
    for _ in range(worker_id * 15):
        best_arr = mutate(best_arr)
        
    best_k = get_k(best_arr)
    
    print(f"Worker {worker_id:02d} | Started. Baseline K: {best_k}")
    
    for _ in range(generations):
        candidate_arr = mutate(best_arr)
        candidate_k = get_k(candidate_arr)
        
        # >= allows lateral movement across flat plateaus in the search space
        if candidate_k >= best_k:
            best_k = candidate_k
            best_arr = candidate_arr
            
    print(f"Worker {worker_id:02d} | Finished. Peak K Found: {best_k}")
    return best_k, best_arr

if __name__ == '__main__':
    N = 100
    # Massively increased target (adjust based on how long you want to wait)
    TOTAL_GENERATIONS = 5_000_000 
    CORES = multiprocessing.cpu_count()
    GENS_PER_CORE = TOTAL_GENERATIONS // CORES
    
    print(f"Starting Multi-Core Hill Climbing Search...")
    print(f"Targeting {TOTAL_GENERATIONS:,} total mutations across {CORES} active cores.\n")
    
    start_time = time.time()
    
    # Bundle arguments for the pool
    worker_args = [(i, GENS_PER_CORE, N) for i in range(CORES)]
    
    # Launch parallel processes
    with multiprocessing.Pool(CORES) as pool:
        results = pool.starmap(worker_hill_climb, worker_args)
        
    # Aggregate results to find the global champion
    global_best_k = 0
    global_best_arr = []
    
    for k, arr in results:
        if k > global_best_k:
            global_best_k = k
            global_best_arr = arr
            
    print(f"\nEvolution complete in {time.time() - start_time:.2f} seconds.")
    print(f"==== ABSOLUTE PEAK K REACHED: {global_best_k} ====")
    
    print("\nWorst Case Array Layout:")
    print(f"[{global_best_arr[0]}, {global_best_arr[1]}, {global_best_arr[2]} ... {global_best_arr[-1]}]")
    
    # Save the nuke to file
    filename = "worst_case.txt"
    with open(filename, "w") as f:
        f.write("1\n")
        f.write(f"{N}\n")
        f.write(" ".join(map(str, global_best_arr)) + "\n")
        
    print(f"\nTest case successfully written to {os.path.abspath(filename)}")