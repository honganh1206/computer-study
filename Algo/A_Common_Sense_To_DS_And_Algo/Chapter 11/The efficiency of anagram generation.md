---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
sr-due: 2024-10-18
sr-interval: 4
sr-ease: 270
---
- For a string containing three characters => $3 * 2 * 1 = 6$ anagrams => **FACTORIAL**
	- Three permutations, each one starts with a character `a[xx], b[xx], c[xx]` => 3
	- Each permutation picks its middle character from the remaining two => 2
	- Remain the last character => 1


- Anagram generation has the time complexity of $O(N!)$