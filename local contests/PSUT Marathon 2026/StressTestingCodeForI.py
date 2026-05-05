import random

def get_next_state(a):
    n = len(a)
    p_min = [0] * n
    s_max = [0] * n
    
    p_min[0] = a[0]
    for i in range(1, n):
        p_min[i] = min(p_min[i-1], a[i])
        
    s_max[n-1] = a[n-1]
    for i in range(n-2, -1, -1):
        s_max[i] = max(s_max[i+1], a[i])
        
    return [p_min[i] ^ s_max[i] for i in range(n)]

global_max_k = 0
best_array = []

for _ in range(1000000):
    n = random.randint(2, 100)
    test_arr = [random.randint(0, 2**60) for _ in range(n)]
    
    steps = 0
    curr = test_arr[:]
    while len(set(curr)) > 1 and steps < 1000:
        curr = get_next_state(curr)
        steps += 1
    
    if steps > global_max_k:
        global_max_k = steps
        best_array = test_arr
        print(f"New Max K: {global_max_k} | Array: {best_array[:3]}...")