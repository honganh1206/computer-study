"""
Return the indexes of the nums in two arrays that need swapping
"""


def sum_swap(arr1, arr2):
    hash_table = {}
    sum1 = 0
    sum2 = 0
    for i in range(len(arr1)):
        sum1 += arr1[i]
        hash_table[arr1[i]] = i
    for i in range(len(arr2)):
        sum2 += arr2[i]

    shift = (sum1 - sum2) / 2

    # Check the number's counterpart
    for i in range(len(arr2)):
        if (arr2[i] + shift) in hash_table:
            return [hash_table[arr2[i] + shift], i]

    return None


print(sum_swap([5, 3, 3, 7], [4, 1, 1, 6]))

