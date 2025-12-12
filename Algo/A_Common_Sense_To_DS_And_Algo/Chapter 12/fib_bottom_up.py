def fib(n):
    if n == 0:
        return 0
    a = 0
    b = 1
    for i in range(1, n):
        temp = a
        a = b # a becomes what b used to be
        b = temp + a # b becomes the sum of (past) b + a
    return b


print(fib(6))
