def add_until_100(arr):
    if len(arr) == 0:
        return 0
    result = add_until_100(arr[1:])
    if arr[0] + result > 100:
        return result
    else:
        return arr[0] + result


print(add_until_100([1, 2, 3, 4, 5]))
