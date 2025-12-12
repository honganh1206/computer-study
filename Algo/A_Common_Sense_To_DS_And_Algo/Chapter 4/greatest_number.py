def find_greatest_number(array):
    greatest_number = array[0] # Suppose that the 1st value is the greatest
    for i in array:
        if i > greatest_number:
            greatest_number = i
    return greatest_number

# Time complexity must be O(N)
print(find_greatest_number([6, 5, 9, 11, -1, 0.35, 1000]))
