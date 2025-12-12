# Arrays & Linked Lists

## Linked lists
- With linked lists, your items can be **anywhere** in memory.
- Each item stores the address of the next item in the list

![[Pasted image 20231018175508.png]]


## Arrays
- You know the addresses/positions/indexes of all elements in the array -> Get the element instantly unlike linked lists

![[Pasted image 20231018232144.png]]

```ad-warning
All elements in an array should be **OF THE SAME TYPE**

```


## Inserting an element into the middle of the list
- Lists are better if **you want to insert elements into the middle**

## Deletions
- Lists are still better, as you just need to **change where the previous element points to**


```ad-important
Insertions and deletions are $O(1)$ time only if **you can instantly access the element to be deleted** (happen mostly with lists)

```

## Access
- Two types of access: *Random access* (Arrays allow this for reading elements) and *Sequential access* (Linked list only)

---
# Selection sort

- Scenario: Sort a list of artists based on number of play counts
- Steps: 
	1. Check each item/artist in the list => $O(n)$
	2. Do step 1 $n$ times => $O(n^2)$
	3. Move each artist to a new list 

![[Pasted image 20231020173746.png]]


```ad-attention
title: Constants in Big O notation
Constants like $1/2$ are **ignored** in Big O notation (Chapter 4 for more detail)

```




---
# Exercises

2.1. Linked list

2.2. Linked list

2.3. Array

2.4. When adding a new elem into an array, that elem will be added at the end of the array, so the array **needs to be sorted** everytime a new elem is added

2.5. Faster than linked list (Arrays start with letters from A to Z) but same amount of time for inserting (Each array slot is a linked list)