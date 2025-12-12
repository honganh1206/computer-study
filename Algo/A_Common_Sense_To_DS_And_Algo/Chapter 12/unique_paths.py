def unique_path(rows, cols, memo={}):
    if rows == 1 or cols == 1:
        return 1
    return unique_path(rows - 1, cols, memo) + unique_path(rows, cols - 1, memo)


print(unique_path(5, 6))
