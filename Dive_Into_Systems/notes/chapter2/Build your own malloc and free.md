---
id: Build your own malloc and free
aliases:
  - Build your own malloc and free
tags: []
---

# Build your own malloc and free

```js
  +----------------------------+
  |         Stack              |  <-- (grows down)
  |        (grows ↓)           |
  +----------------------------+
  |            ↓               |
  +----------------------------+
  | Memory Mapping Segment     |
  +----------------------------+
  |            ↑               |
  +----------------------------+
  |          Heap              |
  |        (grows ↑)           |
  +----------------------------+
  |       BSS segment          |
  +----------------------------+
  |      Data segment          |
  +----------------------------+
  |    Text segment (ELF)      |
  +----------------------------+
```

[[How malloc works under the hood]]

