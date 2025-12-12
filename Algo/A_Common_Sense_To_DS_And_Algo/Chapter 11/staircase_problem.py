def return_num_of_paths(num_of_staircase):
    if num_of_staircase < 0:
        return 0  # 1 path: not climbing at all
    if num_of_staircase == 0 or num_of_staircase == 1:
        return 1
    return (
        return_num_of_paths(num_of_staircase - 1)
        + return_num_of_paths(num_of_staircase - 2)
        + return_num_of_paths(num_of_staircase - 3)
    )

print(return_num_of_paths(11))
