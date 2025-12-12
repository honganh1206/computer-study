def palindrome_checker(str):
    lowercase_str = str.lower()
    leftIndex = 0
    rightIndex = len(lowercase_str) - 1
    while leftIndex < len(lowercase_str) / 2:
        if lowercase_str[leftIndex] != lowercase_str[rightIndex]:
            return False
        leftIndex += 1
        rightIndex -= 1

    return True


print(palindrome_checker("Asa"))
