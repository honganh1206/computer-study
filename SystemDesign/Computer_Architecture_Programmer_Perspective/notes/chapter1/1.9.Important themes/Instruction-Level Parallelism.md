---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
Instruction-Level Parallelism (ILP) is a property of modern processors that allows *multiple instructions to be executed at one time* on a single processor.

When a programmer writes a sequential C program, the processor executes *several* of its instructions simultaneously, in parallel, on one or more execution units

Early microprocessors required multiple (3-10) clock cycles to execute **a single instruction**, while recent processors can execute 2-4 instructions per clock cycle.

Although a single instruction take roughly 20 cycles to finish, the processor uses pipelining (example of ILP) to process as much as 100 instructions at a time. 

[[ILP processor designs]]
