class SortableArray:
    def __init__(self, array):
        self.array = array

    def partition(self, left_pointer, right_pointer):
        # Right-most element as the pivot
        pivot_index = right_pointer
        pivot = self.array[pivot_index]
        # Start at the left of the pivot
        right_pointer -= 1

        while True:
            # Keep moving the left pointer to the right until it reaches an item greater/equal the pivot
            while self.array[left_pointer] < pivot:
                left_pointer += 1
            # Keep moving the right pointer to the right until it reaches an item less/equal the pivot
            while self.array[right_pointer] > pivot:
                right_pointer -= 1
            # We check whether the left pointer has reached
            # or gone beyond the right pointer. If it has,
            # we break out of the loop so we can swap the pivot later
            # on in our code:
            if left_pointer >= right_pointer:
                break
            else:
                # Swap the values of the left and right pointers
                temp = self.array[left_pointer]
                self.array[left_pointer] = self.array[right_pointer]
                self.array[right_pointer] = temp
                left_pointer += 1
        # Swap the value of the left pointer with the pivot
        temp = self.array[left_pointer]
        self.array[left_pointer] = self.array[pivot_index]
        self.array[pivot_index] = temp

        return left_pointer

    def quicksort(self, left_index, right_index):
        # Base case: The sub array has 0 or 1 elem
        if right_index - left_index < 0:
            return
        pivot_index = self.partition(left_index, right_index)
        # Recursive call the quicksort() method the left/right of the pivot
        self.quicksort(left_index, pivot_index - 1)
        self.quicksort(pivot_index + 1, right_index)

    def quickselect(self, kth_lowest_value, left_index, right_index):
        # Base case - sub-array has only 1 cell
        if right_index - left_index <= 0:
            return self.array[left_index]
        pivot_index = self.partition(left_index, right_index)
        # If what we are looking for is to the left of the pivot
        if kth_lowest_value < pivot_index:
            return self.quickselect(kth_lowest_value, left_index, pivot_index - 1)
        elif kth_lowest_value > pivot_index:
            return self.quickselect(kth_lowest_value, pivot_index + 1, right_index)
        else:
            return self.array[pivot_index]


arr = [0, 5, 2, 1, 6, 3]
sortable_arr = SortableArray(arr)
sortable_arr.quicksort(0, len(arr) - 1)
print(sortable_arr.array)
print(
    sortable_arr.quickselect(1, 0, len(arr) - 1)
)  # Find second-to-lowest value of an unsorted array
