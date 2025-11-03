---
id: Parallel Performance Basics
aliases: []
tags: []
---

## Speedup

Suppose a program takes $T_{c}$ time to execute on $c$ cores, while the serial version would take $T_{1}$ time.

The speedup is expressed by this equation: $\text{Speedup}_{c} = \frac{T_{1}}{T_{c}}$

If a serial program takes 60 seconds to execute, its parallel version takes 30 seconds on 2 cores, then the speedup is 2.

If the speedup is greater than 1, that means the parallelization yielded some improvement.

## Efficiency

Measure speedup per core.

$$\text{Efficiency}_{c} = \frac{T_{1}}{T_{c}\times c} = \frac{\text{Speedup}_{c}}{c}$$

Efficiency typically varies from 0 (no benefit to parallelism) to 1 (cores being efficiently used).

## Parallel Performance in the real world

Speedup should be linear. For each additional compute unit, a parallel should achieve a commensurate amount of speedup. However, *this scenario rarely occurs in the real world*.

The longest set of dependencies in a program is referred to as its **critical path**. To achieve parallelization, we must reduce the length of a program's critical path as the 1st step.

> [!warning] Not all programs are good candidates for parallelism
> The critical paths of some program might be too long, like a program that generates Nth Fibonacci number.

The speedup of the program is not always linear with respect to the number of cores. The reasons might be 1) Overhead of assigning work to threads and 2) resource contention by having more threads than cores.