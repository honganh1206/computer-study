---
tags:
  - "#study"
cssclasses:
  - center-images
---
The maximum speedup a computer program can achieve is limited by *the size of its necessarily serial component*.

Less verbose: When we speed up one part of a system, how significant this part is and how much it sped up **impacts** the overall system performance.

Supposed the time to execute some app is $T_{old}$, some part of the system requires a fraction $\alpha$ of this time, and we improve that part’s performance by a factor of $k$. The part **originally** requires $\alpha T_{old}$ and now it requires $\frac{\alpha T_{old}}{k}$

=> The time increased is $\frac{\alpha}{k} - \alpha$

$$
T_{new} = (1-\alpha)T_{old} + \frac{\alpha T_{old}}{k} = T_{old}\left[ (1-\alpha) + \frac{\alpha}{k} \right]
$$

The speedup:

$$
S = \frac{1}{(1-\alpha) + \frac{\alpha}{k}}
$$

[[Expressing relative performance]]

[[Speed up until it takes a negligible amount of time]]

## Analysis

For every program, there is a component that can be sped up (P for parallel) and a component that cannot be sped up (S for serial).

S and P are fractions, note that S + P = 1. When P is reduced to zero, S will increase.

Consider a program that executes on one core in time $T_{1}$. The serial time for the program execution is $S\times T_{1}$ and for the parallelizable fraction  $P\times T_{1}$

With $c$ being the number of cores used, the maximum improvement for the parallel processor with $c$ cores is:

$$
T_{c} = S\times T_{1} + \frac{P}{c} \times T_{1}
$$

As $c$ increases, the execution time on the parallel processor becomes dominated by the serial fraction of the program since $\frac{P}{c}$ becomes smaller.

Have a look at the effect of Amdahl's Law on a 10-second program that is 90% parallelizable:

| Number of cores | Serial time (s) | Parallel time (s) | Total Time (T_c_ s) | Speedup (over one core) |
| --------------- | --------------- | ----------------- | ------------------- | ----------------------- |
| 1               | 1               | 9                 | 10                  | 1                       |
| 10              | 1               | 0.9               | 1.9                 | 5.26                    |
| 100             | 1               | 0.09              | 1.09                | 9.17                    |
| 1000            | 1               | 0.009             | 1.009               | 9.91                    |

Over time, the serial component of the program begins to dominate, and the effect of adding more and more cores seems to have little to no effect.

$$
\text{Speedup}_{c} = \frac{1}{S + \frac{P}{c}}
$$

Consider a program where P = 0.99, meaning 99% of the program is parallelizable. As $c$ approaches infinity, the serial time dominates more (S = 0.01) and speedup approaches 1/0.01 or 100. 

-> Even with a million cores, the maximum speedup achievable is only 100.

This shows the validity of the single processor approach and the weakness of the multiple processor approach in terms of application to real problems.
## Applications:

For razor blade companies: Reduce the cost of manufacturing

For students: Improve his/her grade point average

For computer systems: Improve performance by factors of 2