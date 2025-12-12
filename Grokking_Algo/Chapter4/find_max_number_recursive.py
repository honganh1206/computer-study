def find_maximum(arr):
    if len(arr) == 2:
        if arr[0] > arr[1]:
            return arr[0]
        else:
            return arr[1]
    max = find_maximum(arr[1:])
    if arr[0] > max:
        return arr[0]
    else:
        return max


print(find_maximum([8, 9, 55, 100]))
