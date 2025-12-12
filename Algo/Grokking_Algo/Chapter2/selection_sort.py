def find_smallest(arr):
    smallest_value = arr[0]
    smallest_value_index = 0
    for i in range(1, len(arr)):
        if arr[i] < smallest_value:
            smallest_value = arr[i]
            smallest_value_index = i
    return smallest_value_index

def selection_sort(arr):
    new_arr = []
    for i in range(len(arr)):
        smallest_value = find_smallest(arr)
        new_arr.append(arr.pop(smallest_value))
    return new_arr

print(selection_sort([5, 3, 2, 7, 10]))