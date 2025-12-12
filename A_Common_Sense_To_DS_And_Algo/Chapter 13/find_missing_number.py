def find_missing_number(arr):
    sorted_arr = sorted(arr)
    for i in range(len(sorted_arr) - 1):
        if i not in sorted_arr:
            return i
    return None


print(find_missing_number([0, 1, 3, 4]))
