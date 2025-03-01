---
id: Self-Referential Structs
aliases:
  - Self-Referential Structs
tags: []
---

# Self-Referential Structs

A struct can be defined with fields whose type is **a pointer to the same struct type**

These self-referential `struct` types could be used to build _linked implementations of data structures_ like linked lists, trees, and graphs

Here we will have a simple example of [[Linked Lists]] using self-referential `struct` type

```js
Stack:         Heap:
+-------+
| head  | ---> [ 1 ] ---> [ 0 ] ---> [ 10 ] ---> NULL
+-------+
| temp  | ---^
+-------+
| i: 2  |
+-------+
```
