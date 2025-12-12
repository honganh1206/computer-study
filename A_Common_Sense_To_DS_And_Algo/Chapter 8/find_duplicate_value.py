def find_duplicate(string_arr):
    hash_table = {}
    """
    a DS that keeps track of the value encountered before
    then quickly determine if the value is duplicate
    """
    for index in range(len(string_arr)):
        if string_arr[index] not in hash_table:
            hash_table[string_arr[index]] = True
        else:
            return string_arr[index]


print(find_duplicate(["a", "b", "c", "a", "b"]))
