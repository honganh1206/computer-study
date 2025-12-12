def find_intersection(arr1, arr2):
    intersection = []
    hash_table = {}
    for value in arr1:
        hash_table[value] = True
    for value in arr2:
        if value in hash_table:
            intersection.append(value)
    return intersection


print(find_intersection([1, 2, 3, 4, 9, 10], [1, 2, 3, 8, 9, 31]))
