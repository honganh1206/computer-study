def two_sum(array=None):
    if array is None:
        array = []
    hash_tbl = {}
    for i in range(len(array)):
        if 10 - array[i] in hash_tbl:
            return True
        hash_tbl[array[i]] = True
    return False


print(two_sum([2, 5, 6, 4, 1, 3]))
