# Algorithm that finds the greatest product of three numbers from a given array


def find_largest_product(arr):
    largest_product_so_far = arr[0] * arr[1] * arr[2]
    i = 0
    arr_length = len(arr)
    while i < arr_length:
        j = i + 1
        while j < arr_length:
            k = j + 1
            while k < arr_length:
                potential_largest_product = arr[i] * arr[j] * arr[k]
                if potential_largest_product > largest_product_so_far:
                    largest_product_so_far = potential_largest_product
                k += 1
            j += 1
        i += 1
    return largest_product_so_far


print(find_largest_product([4, 6, 2, 5, 3, 7, 1]))
