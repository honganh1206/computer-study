# Dealing with space constraints

> [!summary] 3-sentence summary
> - We have to consider the space constraints (memory management) alongside with the time constraints (steps taken to complete), as we cannot have both at the same time.
> - The space complexity only focuses on the **additional space** required by the function and not the input itself.
> - When dealing with recursion, we need to calculate how big the call stack at its speak to store enough recursion calls.
> 


- Another factor worth great consideration is how much **memory** an algorithm consumes

## Big O of Space Complexity

- The key question: If there are $N$ data elements, how many units of memory will the algorithm consume?

```js
// This function creates a new array with N elements at the end
function makeUppercase(array) {
	let newArray = [];
	for(let i = 0; i < array.length; i++) {
		newArray[i] = array[i].toUpperCase();
	}
	return newArray;
}

// A more efficient version
function makeUppercase(array) {
	for(let i = 0; i < array.length; i++) {
		array[i] = array[i].toUpperCase();
	}
	return array;
}

```

![[Pasted image 20240824105053.png|The vertical axis now represents memory]]


> [!info] Auxiliary space
> 
> As the original array exists in any case, we only focus on the **extra** space the algorithm consumes, which is known as **auxiliary space**.


## Trade-Offs between time and space

```js
// New version with a hash table
function hasDuplicateValue(array) {
	let existingValues = {};
	for(let i = 0; i < array.length; i++) {
		if(!existingValues[array[i]]) {
			existingValues[array[i]] = true;
		} else {
			return true;
		}
	}
	return false;
}
```

- This new version of `hasDuplicateValue()` is more time-efficient (we only have to iterate through the array once) but less space-efficient (we have to create a new hash table)

```js
// A more balanced version with both time and space complexity of O(NlogN)
function hasDuplicateValue(array) {
	array.sort((a, b) => (a < b) ? -1 : 1);
	for(let i = 0; i < array.length - 1; i++) {
		if (array[i] === array[i + 1]) {
			return true;
		}
	}
	return false;
}
```

## The Hidden Cost of Recursion

```js
// A typical recursive function adding an item in a call stack
// We can only come back to the outer function once the inner one is executed
function recurse(n) {
	if (n < 0) { return; }
	console.log(n);
	recurse(n - 1);
}

// While this function takes a while to complete with a large number of input, it does not take up additional memory
function loop(n) {
	while (n >= 0) {
		console.log(n);
		n--;
	}
}
```

- **As a recursive function takes up an unit of space for each recursive call it makes**, we need to be aware that we have enough memory in the call stack for deep recursive functions by calculating how big the call stack would be at its peak

## Exercises

Ex1
- Time: $O(N^2)$
- Space $O(N^2)$ with $N$ elements in the array and $N-1$ concatenations to make

Ex2

- Time: $O(N)$
- Space: $O(N)$


Ex3

```js
function reverse(array) {
	for (let i = 0; i < array.length / 2; i++) {
		[array[i], array[(array.length - 1) - i]] =
		[array[(array.length - 1) - i], array[i]];
	}
	return array;
}
```

Ex4


| Version | Time Complexity | Space Complexity |
| ------- | --------------- | ---------------- |
| 1       | O(N)            | O(N)             |
| 2       | O(N)            | O(1)             |
| 3       | O(N)            | O(N)             |
