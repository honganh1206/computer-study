def insertion_sort(array):
    for index in range(1, len(array)):
        temp_value = array[index]  # Store the value at index 1 as a temp
        leftward_value_index = index - 1  # Get the index of the leftward value
        # Shifting phases until reaching the end of the array
        while leftward_value_index >= 0:
            # If the leftward value >= temp value, shift the leftward value to the right
            if array[leftward_value_index] > temp_value:
                array[leftward_value_index + 1] = array[leftward_value_index]
                # Compare the next value against the temp value in the next iteration
                leftward_value_index = leftward_value_index - 1
            # If not => End the shifting phase and get the value on the right as the new temp value
            else:
                break
        # Insert the temp value to the gap
        array[leftward_value_index + 1] = temp_value
    return array


print(insertion_sort([4, 11, 9, 44]))
