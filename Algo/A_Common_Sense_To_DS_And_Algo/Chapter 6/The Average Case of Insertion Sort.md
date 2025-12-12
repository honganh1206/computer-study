---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---

> [!info]
> 
> Best- and worst-case scenarios happen relatively infrequently. In the real world, **average scenarios are what occur most of the time**.

- The performance of Insertion Sort varies greatly based on the scenario.

![[Pasted image 20240219172549.png]]


### When to use what

- If you have reason to assume you’ll be dealing with data that is **mostly sorted**, Insertion Sort will be a better choice. 
- If you have reason to assume you’ll be dealing with data that is **mostly sorted in reverse order**, Selection Sort will be faster.

## A Practical Example

- Scenario: Finding the **intersection** (as an array) between two arrays

```js
function intersection(firstArray, secondArray){
	let result = [];
	for (let i = 0; i < firstArray.length; i++) {
		for (let j = 0; j < secondArray.length; j++) {
			if (firstArray[i] == secondArray[j]) {
				result.push(firstArray[i]);
				break; // break out of the loop when finding a common value => No need to complete the second loop
			}
		}
	}
	return result;
}
```