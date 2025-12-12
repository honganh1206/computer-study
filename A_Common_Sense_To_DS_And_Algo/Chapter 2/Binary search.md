---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
- Scenario: Search for value of $n$
- Step 1: Jump into the central cell (take the array's index and dividing it by 2) then check the value
- Step 2: Eliminate the half of the array where 7 does not belong to
- Step 3: Inspect the middlemost value of the remaining half (Step 1) and remove the unqualified half again (Step 2)
- Step 4: Repeat until the value $n$ is found

```ruby
def binary_search(array, search_value)
	lower_bound = 0 # 1st value in the array
	upper_bound = array.length - 1 # last value in the array

	while lower_bound <= upper_bound do
		mid_point = (upper_bound + lower_bound) / 2
		value_at_mid_point = array[mid_point]
		if search_value == value_at_mid_point
			return mid_point
		elsif search_value < value_at_mid_point
			# making the upper_bound the index to the left of the mid point
			upper_bound = mid_point - 1
		elsif search_value > value_at_mid_point
			# making the lower_bound the index to the right of the mid point
			lower_bound = mid_point + 1
		end
	end
	return nil
end
```

