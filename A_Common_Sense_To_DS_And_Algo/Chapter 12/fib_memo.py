def fib(n, memo = {}):
    if n == 0 or n == 1:
        return n
    # Check in the hash table whether fib(n) has been computed or not
    if not memo.get(n):
        memo[n] = fib(n - 2, memo) + fib(n - 1, memo) # Pass the memo var to store the result whenever we recursively call the `fib()`function
    return memo[n]


print(fib(6, {}))
