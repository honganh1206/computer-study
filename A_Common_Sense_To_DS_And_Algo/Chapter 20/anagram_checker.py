def check_anagrams(first_str, second_str):
    first_str_hash_table = {}
    second_str_hash_table = {}
    for char in first_str:
        if first_str_hash_table.get(char):
            first_str_hash_table[char] += 1
        else:
            first_str_hash_table[char] = 1

    for char in second_str:
        if second_str_hash_table.get(char):
            second_str_hash_table[char] += 1
        else:
            second_str_hash_table[char] = 1

    return first_str_hash_table == second_str_hash_table


print(check_anagrams("abc", "bca"))
