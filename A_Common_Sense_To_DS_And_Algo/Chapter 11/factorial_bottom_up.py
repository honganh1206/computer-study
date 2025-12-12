def factorial(n, i=1, product=1):
    if i > n:
        return product # var to store the calculation
    return factorial(n, i + 1, product * i)

print(factorial(9))
