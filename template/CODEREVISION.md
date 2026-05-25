## bound midpoint

Minimizes the maximum travel time on a 1D line where each point has a delay/cost t[i].

File: [1730B](../codeforces/B/1730.cpp)

### Minimal Proof
```text
Goal: Minimize max(t[i] + |x[i] - x_0|)

1. Expand absolute value:
   t[i] + |x[i] - x_0| = max(x[i] + t[i] - x_0, x_0 - (x[i] - t[i]))

2. Let R[i] = x[i] + t[i] and L[i] = x[i] - t[i]. Over all elements:
   Max Time = max(max(R[i]) - x_0, x_0 - min(L[i]))

3. Let mx = max(R[i]) and mn = min(L[i]). To minimize the maximum 
   of these two opposing linear functions, set them equal:
   mx - x_0 = x_0 - mn  =>  2 * x_0 = mx + mn  =>  x_0 = (mx + mn) / 2
```