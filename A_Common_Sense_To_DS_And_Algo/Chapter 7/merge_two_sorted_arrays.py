# An algorithm that merges two sorted arrays together to create a new sorted array containing all the values from both arrays


def merge(arr1, arr2):
    new_arr = []
    arr1_length = len(arr1)
    arr2_length = len(arr2)
    arr1_pointer = 0
    arr2_pointer = 0
    # Run the loop until reaching the ends of both arrs
    while arr1_pointer < arr1_length and arr2_pointer < arr2_length:
        # If the current number in the 1st array is less than the current number of the second array, add the former number and vice versa
        if arr1[arr1_pointer] < arr2[arr2_pointer]:
            new_arr.append(arr1[arr1_pointer])
            arr1_pointer += 1
        else:
            new_arr.append(arr2[arr2_pointer])
            arr2_pointer += 1

    # Add remaining elements from arr1, if any
    while arr1_pointer < arr1_length:
        new_arr.append(arr1[arr1_pointer])
        arr1_pointer += 1

    # Add remaining elements from arr2, if any
    while arr2_pointer < arr2_length:
        new_arr.append(arr2[arr2_pointer])
        arr2_pointer += 1

    return new_arr


print(merge([1, 2, 3], [4, 5, 6]))
