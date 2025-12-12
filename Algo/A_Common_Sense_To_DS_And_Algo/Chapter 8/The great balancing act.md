---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
sr-due: 2025-09-28
sr-interval: 3
sr-ease: 250
---
Scenario:
- A hash function that always produces a value that **falls in the range from 1 to 9**
- A hash table with 16 cells

=> The computer would never even use cells 10 through 16 even though they exist. All data would be stuffed into cells 1 through 9.


> [!tip]
> 
> A good hash function, therefore, is one that distributes its data across all available cells.

> [!note]
> 
> While avoiding collisions is important, we have to **balance that with avoiding memory hogging** as well.

> [!success] Load factor
> 
>  For every 7 data elements stored in a hash table, it should have 10 cell