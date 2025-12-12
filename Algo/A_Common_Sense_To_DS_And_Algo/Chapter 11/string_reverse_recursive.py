def reverse(str):
    arr = [char for char in str]
    if len(arr) == 1:
        return arr[0]
    return reverse(arr[1:]) + arr[0]


print(reverse("abcde"))
