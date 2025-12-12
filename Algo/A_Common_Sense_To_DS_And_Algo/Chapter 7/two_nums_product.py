# Algorithm that accepts an array of numbers and returns the product of every combination of two numbers
def two_nums_product(array):
    products = []
    array_length = len(array)
    for i in range(0, array_length - 1):
        for j in range(i + 1, array_length):
            products.append(array[i] * array[j])

    return products


print(two_nums_product([3,6,9]))
