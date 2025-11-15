def multiply(num1, num2):
    return num1 * num2

def scalar_multiply(array, s):
    # Using list comprehension (A kind of map operation in FP)
    return [multiply(x, s) for x in array]

my_arr = [1, 3, 5, 7, 9]
result = scalar_multiply(my_arr, 2)

print(result)
