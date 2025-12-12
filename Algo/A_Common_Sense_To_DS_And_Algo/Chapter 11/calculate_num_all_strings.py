def calculate_chars(arr_strings):
    if len(arr_strings) == 0:
        return 0

    return len(arr_strings[0]) + calculate_chars(arr_strings[1:])


print(calculate_chars(["a", "bcd"]))
