---
id: Heap memory management
aliases:
  - Heap memory management
tags: []
---

# Heap memory management

After [`malloc` requests a contiguous chunk of unallocated heap memory](./malloc and free.md), the heap memory manager maintains a **free list of unallocated extents of heap memory**.

Each extent specifies the **start address** and **size** of a contiguous unallocated chunk of heap space

Think of this like a linked list:

```yaml
Heap Memory:
| 0x1000 (16KB) | 0x5000 (8KB) | 0x7000 (12KB) | 0xA000 (20KB) |

Free List (Linked List Representation):
[ Start: 0x1000, Size: 16KB ] --> [ Start: 0x5000, Size: 8KB ] --> [ Start: 0x7000, Size: 12KB ] --> [ Start: 0xA000, Size: 20KB ] --> NULL
```

At first, _all heap memory is empty_, and the free list has a **single extent** consisting of the entire heap region

After some calls to `malloc` and `free`, heap memory becomes **fragmented**: Chunks of free heap space interspersed with chunks of allocated heap space

## How the heap memory manager keeps track of free locations

The heap memory manager keeps lists of _different ranges_ of sizes of heap space, so it can perform fast searching for a free extent of a specific size.

The manager also implements one or more policies to choose among multiple free extents that could satisfy a request
