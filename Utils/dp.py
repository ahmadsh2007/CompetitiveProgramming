def fib(n, memo):
    if memo[n] is not None:
        return memo[n]
    if n == 1 or n == 2:
        result = 1
    else:
        result = fib(n-1, memo) + fib(n-2, memo)
    memo[n] = result
    return result

def fib_memo(n):
    memo = [None] * (n + 1)
    return fib(n, memo)

print(fib_memo(100))

def fib2(n):
    val = [None] * 3;
    val[0] = 0
    val[1] = 1
    for _ in range(2, n + 1):
        val[_ % 3] = val[(_ - 1) % 3] + val[(_ - 2) % 3];
    return val[n % 3]

print(fib2(100))