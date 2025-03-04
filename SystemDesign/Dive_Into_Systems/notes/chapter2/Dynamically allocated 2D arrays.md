---
id: Dynamically allocated 2D arrays
aliases:
  - Dynamically allocated 2D arrays
tags: []
---

# Dynamically allocated 2D arrays

To dynamically allocate a 2D array, we can either:

1. Make a **single** call to `malloc` requesting a large chunk of heap space to store `N x M` elements - [[Method 1 - Single malloc]]
2. Make **multiple** calls to `malloc` allocating an **array of arrays** - [[Method 2 - Multiple mallocs]]
