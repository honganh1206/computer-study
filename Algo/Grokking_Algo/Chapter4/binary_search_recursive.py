def binary_search_recursive(arr, target, low=0, high=None):
    if high is None:
        high = len(arr) - 1

    if low > high:  # Base case to handle empty list/target element not in the list
        return -1

    if len(arr) == 1:
        if arr[0] == target:
            return 0

    mid = (low + high) // 2

    guess = arr[mid]

    if guess == target:
        return mid
    elif guess > target:
        return binary_search_recursive(arr, target, low, mid - 1)
    else:
        return binary_search_recursive(arr, target, mid + 1, high)


print(binary_search_recursive([1, 2, 3, 4, 5, 6], 5))
