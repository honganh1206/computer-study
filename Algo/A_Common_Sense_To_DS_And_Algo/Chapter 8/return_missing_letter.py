import string


def return_missing_letter(str):
    hash_table = {}
    alphabet = list(string.ascii_lowercase)

    for index in range(len(str)):
        hash_table[str[index]] = True # Value set to True to indicate presence of letter only

    for index in range(len(alphabet)):
        if alphabet[index] not in hash_table:
            return alphabet[index]


print(return_missing_letter("the quick brown box jumps over a lazy dog"))
