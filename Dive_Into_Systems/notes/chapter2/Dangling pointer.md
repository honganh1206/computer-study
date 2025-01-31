---
id: Dangling pointer
aliases:
  - Dangling pointer
tags: []
---

# Dangling pointer

After we call `free`, the pointer _still contains the address of the freed memory_, but **this memory location is no longer valid to access**, thus creating a dangling pointer

The dangling pointer can result in program crashes, undefined behaviors, security vulnerabilities, etc.
