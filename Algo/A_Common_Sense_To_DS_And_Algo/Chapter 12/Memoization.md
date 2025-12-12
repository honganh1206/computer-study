---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#algorithm"
cssclasses:
  - center-images
---
Memoization can reduce recursive calls by **remembering** previously computed functions and **store it inside a hash table**. For example, when `fib(3)` is called, the function returns the value 2 and we store it inside a hash table => `{ 3:2 }`

![[Pasted image 20240427211519.png]]

Each call that is surrounded by a box is **the one whose result is retrieved from the hash table**.