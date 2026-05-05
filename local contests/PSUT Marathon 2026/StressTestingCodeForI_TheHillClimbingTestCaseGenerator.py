import random
import time
import os

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

if __name__ == '__main__':
    N = 100
    GENERATIONS = 500_000
    
    # Start with a "smart" anti-heuristic guess: 
    # Alternating massive powers of 2 and 0s to force stair-stepping
    best_arr = [(1 << (60 - i//2)) if i % 2 == 0 else 0 for i in range(N)]
    best_k = get_k(best_arr)
    
    print(f"Starting Hill Climbing...")
    print(f"Initial Baseline K: {best_k}")
    
    start_time = time.time()
    
    for gen in range(GENERATIONS):
        # Create a mutated offspring
        candidate_arr = mutate(best_arr)
        candidate_k = get_k(candidate_arr)
        
        # If the offspring is better (or equal, to allow lateral movement across the search space)
        if candidate_k >= best_k:
            # If it's strictly better, log it
            if candidate_k > best_k:
                print(f"Generation {gen} | New Max K Found: {candidate_k}")
                
            best_k = candidate_k
            best_arr = candidate_arr
            
    print(f"\nEvolution complete in {time.time() - start_time:.2f} seconds.")
    print(f"Absolute Peak K Reached: {best_k}")
    
    # Save to file
    with open("worst_case.txt", "w") as f:
        f.write("1\n")
        f.write(f"{N}\n")
        f.write(" ".join(map(str, best_arr)) + "\n")