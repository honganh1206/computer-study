def return_non_duplicate_letter(str):
    seen_hash_table = {}
    """
    Return FIRST NON-DUPLICATE letter of a string
    """
    for letter in str:
        if letter not in seen_hash_table:
            seen_hash_table[letter] = True
        else:
            seen_hash_table[letter] = False

    return [letter for letter in seen_hash_table if seen_hash_table[letter]][0]


print(return_non_duplicate_letter("minimum"))
