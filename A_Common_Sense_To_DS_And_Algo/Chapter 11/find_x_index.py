def find_x_index(string):
    # Base case #1: string is empty => x not found
    if len(string) == 0:
        return -1
    if string[0] == "x":
        return 0
    index = find_x_index(string[1:])
    if index == -1:
        return -1  # x was not found for the rest of the string
    else:
        return index + 1


print(find_x_index("abcdefghijklmnopqrstuvwxyz"))
