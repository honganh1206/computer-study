---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
```js
function hasDuplicateValue(array) {
	for (let i = 0; i < array.length; i++) {
		for (let j = 0; j < array.length; j++) {
			if (i !== j && array[i] === array[j]) {
				return true;
			}
		}
	}
	return false; // Worst-case scenario as we have run through every element of the array and found no duplicate
}
```

> [!info]
> Very often (but not always), when an algorithm nests one loop inside another, the algorithm is $O(n^2)$

```js
// Improved linear solution 
function hasDuplicateKey(array) {
	let existingNumbers = [];
	for (let i = 0; i < array.length; i++) {
		if (existingNumbers[array[i]] === 1) {
			return true;
		} else {
			existingNumbers[array[i]] = 1; // Place an arbitrary value for each number we encounter
		}
	}
	return false; // If we get to the end of the loop without having returned true, it means there are no duplicates and we return false.
}
```

- Explanation with the sample array `[3,5,8]`:
	- When we encounter the `3`, we *place a `1` at index = 3 of `existingNumbers`* => We got an array of `[undefined, undefined, undefined, 1]` at the start
	- After iterating through all elements, we end up with *the array `existingNumbers` filled with `undefined` and `1` values, and their indexes are the numbers in the original array*
	- While iterating though each element, we check which index of the `existingNumbers` already has the arbitrary value `1` assigned to it
		- If yes => Return `true` and break the function
		- If no => Assign the arbitrary value and continue the iteration