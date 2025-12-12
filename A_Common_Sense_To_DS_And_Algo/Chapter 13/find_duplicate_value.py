def find_duplicate_value(arr):
    # Pre-sort the array
    arr.sort()
    for i in range(len(arr) - 1):
        if arr[i] == arr[i + 1]:
            return True
    return False


print(find_duplicate_value([4, 4, 3, 2, 1]))
