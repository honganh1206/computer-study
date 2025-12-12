array = [
    1,
    2,
    3,
    [4, 5, 6],
    7,
    [8, [9, 10, 11, [12, 13, 14]]],
    [15, 16, 17, 18, 19, [20, 21, 22, [23, 24, 25, [26, 27, 29]], 30, 31], 32],
    33,
]


def extract_nums_from_nested_arr(nested_arr):
    nums = []
    for elem in nested_arr:
        if type(elem) == list:
            # Add all elements from an iterable
            nums.extend(extract_nums_from_nested_arr(elem))
        else:
            nums.append(elem)
    return nums


print(extract_nums_from_nested_arr(array))
