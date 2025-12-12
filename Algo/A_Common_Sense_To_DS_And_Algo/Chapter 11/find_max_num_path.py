def find_max_num_path(num_row, num_col):
    # Base case: 1 path for 1x1 grid
    if num_col == 1 and num_row == 1:
        return 1
    # Base case: 2 paths for 2x1 or 1x2 grid
    if (num_col == 1 and num_row == 2) or (num_col == 2 and num_row == 1):
        return 2
    # Base case: 2 paths for 2x2 grid
    if num_col == 2 and num_row == 2:
        return 2
    # Recursive case: sum of paths from left and above
    return find_max_num_path(num_row - 1, num_col) + find_max_num_path(
        num_row, num_col - 1
    )


print(find_max_num_path(3, 3))
