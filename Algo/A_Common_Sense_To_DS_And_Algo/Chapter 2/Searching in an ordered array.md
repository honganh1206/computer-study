---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
sr-due: 2025-09-28
sr-interval: 3
sr-ease: 250
---
Linear search - Check each cell one at a time *from left to right* until we find the value we want

```ruby
def linear_search(array, search_value)
	array.each_with_index do |element, index|
		if element == search_value
			return index
		elsif element > search_value
			break
		end # Indicate the end of a code block
	end

	return nil
end
```

> [!note]
> 
> Linear search can take *fewer steps* in an ordered array than in a classic array