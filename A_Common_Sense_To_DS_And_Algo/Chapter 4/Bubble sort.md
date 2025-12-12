---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
- Why "bubble"? => In each pass-through, the highest unsorted value **bubbles up** to its correct position

> [!tldr] How it works
> 
> 1. Point the two **consecutive values** in the array (starting with the 1st value of the array) then compare the 1st item with the 2nd item
> 2. Swap the two items if they are out of order
> 3. Move the **pointers** one cell to the right
> 4. **Repeat step 1 through 3** until we reach the end
> 5. Move the pointers back to the **1st two values of the array** and execute step 1 to 4 again **until we have a pass-though (no need to perform any swaps)**


```python
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
```


[[The efficiency of bubble sort]]

