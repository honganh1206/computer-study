
> [!summary] 3-sentence summary
> 
> - Insertion sort builds up a sorted portion of the array at the beginning, then insert each new element into its correct position within the sorted array.
> - Insertion sort is not really efficient as it takes $O(N^{2})$ to complete.
> - In the real world, average-case scenarios happen the most.

[[Insertion Sort]]


> [!tip]
> 
> Being able to discern between best-, average-, and worst-case scenarios is a **key skill** in choosing the best algorithm for your needs, as well as taking existing algorithms and optimizing them further to make them significantly faster. 

## Exercises

1. $O(N^2)$
2. $O(N)$
3. Best: First two numbers adding up to 10 / Average: Two numbers are somewhere in the middle of the arrays / Worst: No numbers adding up to 10 => $O(N^2)$
4. $O(N)$

```js
function containsX(string) {
	for (let i = 0; i < string.length; i++) {
		if (string[i] === "X") {
			return true;
		}
	}
	return false;
}
```