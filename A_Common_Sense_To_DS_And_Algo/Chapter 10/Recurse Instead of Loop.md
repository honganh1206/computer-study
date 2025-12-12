---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---

> [!warning] Using recursion
> 
> Just because you CAN use recursion, that does not mean you SHOULD use recursion all the time. Recursion is a tool that allows writing **elegant** code.


## The base cases


```js
function countdown(number) {
	console.log(number);
	if (number === 0) { // the base case
		return;
	} else {
		countdown(number - 1)
	}
}
```