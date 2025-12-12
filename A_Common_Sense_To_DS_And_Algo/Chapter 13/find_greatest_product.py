def find_greatest_product(positive_arr):
    sorted_positive_arr = sorted(positive_arr)
    n = len(positive_arr)
    return (
        sorted_positive_arr[n - 1]
        * sorted_positive_arr[n - 2]
        * sorted_positive_arr[n - 3]
    )

print(find_greatest_product([5,4,8,2,7]))
