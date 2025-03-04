---
id: Simplicity
aliases:
  - Simplicity
tags: []
---

# Simplicity

A small project can have simple and expressive code, but as projects grow, the codebase become more difficult to understand

The reasons for increasing complexity vary: Tight coupling of modules, tangled dependencies, hacks to solve performance problems, etc.

Our key goal is to **reduce complexity** and we can _remove accidental complexity_

One of the best tools to remove accidental complexity is **abstraction**. A good abstraction _hide a great deal of implementation detail_ behind a simple facade. An example would be _high-level programming languages_ that hide machine code, CPU registers, syscalls, etc.

Finding good abstractions is hard: We must be clear about how we package algorithms into abstractions to keep the complexity at manageable level
