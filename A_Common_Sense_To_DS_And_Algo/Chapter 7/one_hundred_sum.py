"""
Return true if
- Its first and last numbers add up to 100.
- Its second and second-to-last numbers add up to 100.
- Its third and third-to-last numbers add up to 100, and so on.
"""


def one_hundred_sum(array):
    array_length = len(array)
    left_index = 0
    right_index = array_length - 1
    while left_index < array_length / 2:
        if array[left_index] + array[right_index] != 100:
            return False
        left_index += 1
        right_index -= 1
    return True


print(one_hundred_sum([1, 2, 98, 99]))
