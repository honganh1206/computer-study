def get_even_num(num_arr):
    if len(num_arr) == 0:
        return []
    # NOTE: get_even_num is never called until we reach the base case 
    if num_arr[0] % 2 == 0:
        return [num_arr[0]] + get_even_num(num_arr[1:])
    else:
        return get_even_num(num_arr[1:])


print(get_even_num([1, 2, 3, 4, 5]))
