---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
1. Create stacks with the quantity depending on the number of characters

![[anagram_callstack]]


2. The base case is out first => Return an array consisting of the only chars `["d"]`
3. Get the string of the second stack `"cd"`
4. Insert the 1st character of the string `"c"` into each position of the substring anagram `"d"` =>  Anagrams `["cd", "dc"]`

![[insert_char_to_anagrams|200]]
5. Add the anagrams to the collection
6. Repeat from 3 → 5 with the next stacks
7. Return the collection
