---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
### Initial Array:
```
[5, 2, 9, 1, 5, 6]
```

### Step 1: First Pass (i=1)
- **Key**: `2`
- **Sorted Part**: `[5]`
- **Compare**: `2 < 5`
- **Action**: Move `5` to the right, Insert `2`

```
[2, 5, 9, 1, 5, 6]
```

### Step 2: Second Pass (i=2)
- **Key**: `9`
- **Sorted Part**: `[2, 5]`
- **Compare**: `9 > 5`
- **Action**: No changes, `9` stays in place

```
[2, 5, 9, 1, 5, 6]
```

### Step 3: Third Pass (i=3)
- **Key**: `1`
- **Sorted Part**: `[2, 5, 9]`
- **Compare**: `1 < 9`, `1 < 5`, `1 < 2`
- **Action**: Move `9`, `5`, and `2` to the right, Insert `1`

```
[1, 2, 5, 9, 5, 6]
```

### Step 4: Fourth Pass (i=4)
- **Key**: `5`
- **Sorted Part**: `[1, 2, 5, 9]`
- **Compare**: `5 < 9`, `5 = 5`
- **Action**: Move `9` to the right, Insert `5`

```
[1, 2, 5, 5, 9, 6]
```

### Step 5: Fifth Pass (i=5)
- **Key**: `6`
- **Sorted Part**: `[1, 2, 5, 5, 9]`
- **Compare**: `6 < 9`, `6 > 5`
- **Action**: Move `9` to the right, Insert `6`

```
[1, 2, 5, 5, 6, 9]
```

### Final Sorted Array:
```
[1, 2, 5, 5, 6, 9]
```

### Visualization in Code:
```python
def insertion_sort_visualized(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        print(f"Key: {key}")
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
        print(f"After inserting {key}: {arr}")
    return arr

# Example array
array = [5, 2, 9, 1, 5, 6]
print("Initial array:", array)
sorted_array = insertion_sort_visualized(array)
print("Sorted array:", sorted_array)
```