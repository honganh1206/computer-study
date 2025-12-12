def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(
            0, n - i - 1
        ):  # loop through an array to the part which is not yet sorted
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break
    return arr


print(bubble_sort([5, 4, 6, 8, 2, 1, 7, 0]))
