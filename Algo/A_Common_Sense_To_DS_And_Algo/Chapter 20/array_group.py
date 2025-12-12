def group_array(arr):
    hash_table = {}
    new_arr = []

    for value in arr:
        if hash_table.get(value):
            hash_table[value] += 1
        else:
            hash_table[value] = 1

    for key, count in hash_table.items():
        for _ in range(count):
            new_arr.append(key)

    return new_arr


print(group_array(["a", "b", "d", "a", "b"]))
