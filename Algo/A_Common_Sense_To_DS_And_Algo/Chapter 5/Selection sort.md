---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
## Steps

1. Check if cell from left to right to determine which value is the lowest + Store its index in a variable
2. Replace the index with the index of the even lower value when found

![[Pasted image 20240205091102.png]]

3. Swap the values

![[Pasted image 20240205091509.png]]

4. Repeat step 1 to 3

> [!tip]
> 
> For each pass through, the leftmost cells are already sorted, so for the $n$ pass through we start at the $n$ index


![[Pasted image 20240205091808.png]]

## Efficiency of Selection Sort

![[Pasted image 20240205094355.png]]