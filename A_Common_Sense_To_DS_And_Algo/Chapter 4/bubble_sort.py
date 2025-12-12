def bubble_sort(list):
    unsorted_list_index = len(list) - 1 # Keep track of the RIGHTMOST index of the array
    is_sorted = False

    while not is_sorted:
        is_sorted = True # Assume the array is sorted until we encounter a swap in each pass-through
        for i in range(unsorted_list_index): # Point to each pair of values in the array
            if list[i] > list[i+1]:
                list[i], list[i+1] = list[i+1], list[i]
                is_sorted = False # Change the flag back if we have to make a swap
        unsorted_list_index -= 1 # The value we BUBBLE UP ALL THE WAY TO THE RIGHT is now in the correct position => The index pointed to is now sorted

    return list

print(bubble_sort([5,7,3,2,4]))
