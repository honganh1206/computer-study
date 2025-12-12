def max_sum(arr):
    current_sum = 0
    greatest_sum = 0

    for num in arr:
        if current_sum + num < 0:
            current_sum = 0
        else:
            current_sum += num
            if current_sum > greatest_sum:
                greatest_sum = current_sum

    return greatest_sum


# print(max_sum([5, 3, -1, 4, 9]))


def increasing_triplet(arr):
    lowest = arr[0]
    middle = float("inf")
    for price in arr:
        if price <= lowest:
            lowest = price
        elif price <= middle:
            middle = price
        else:
            return True

    return False


print(increasing_triplet([5, 4, 2, 7, 10]))
