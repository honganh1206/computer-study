def selection_sort(arr):
    arr_length = len(arr)
    for i in range(0, arr_length - 1):
        lowest_number_index = i
        # continue looping from the current element to the end to find an even lower value
        for j in range(i, arr_length - 1):
            if arr[j] < arr[lowest_number_index]:
                lowest_number_index = j
        if lowest_number_index != i:
            arr[i], arr[lowest_number_index] = arr[lowest_number_index], arr[i]

    return arr


print(selection_sort([3, 6, 1, 2, 7]))
