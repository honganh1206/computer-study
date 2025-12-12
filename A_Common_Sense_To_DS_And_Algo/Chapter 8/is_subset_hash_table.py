def is_subset(arr1, arr2):
    larger_arr = []
    smaller_arr = []
    hash_table = {}
    if len(arr1) > len(arr2):
        larger_arr = arr1
        smaller_arr = arr2
    else:
        larger_arr = arr2
        smaller_arr = arr1

    # Hash the larger array
    for value in range(0, len(larger_arr)):
        hash_table[value] = True

    for value in range(0, len(smaller_arr)):
        if hash_table[value] == False:
            return False
    return True


print(is_subset([1, 2, 3], [1, 2]))
