The initial idea is to *re-evaluate [[Amdahl’s Law]]*.

Gustafson argues that the number of compute cores (c) and the parallelizable of the program (P) are *never* independent of each other.

In the real world, more cores/processors are added as the problem grows large, which means it is more realistic to *assume runtime is constant, not problem size* which Amdahl's law assumes it to be so.

Gustafson thus concludes that "The amount of work that can be done in parallel varies linearly with the number of processors", meaning as *we get more processing power, we increase the size/complexity of the problem while keeping total runtime roughly constant*.

Gustafson also argues "speedup should be measured by scaling the problem to the number of processors, not by fixing a problem size" to help *doing more work in a constant amount of time*.

## Analysis

Given a program that takes $T_{c}$ to run on a system with $c$ cores.

When the same program is run on just one core, the serial fraction of the code still takes $S\times T_{c}$ , but the parallelizable fraction now has to be executed by just one core to run serially, thus taking $P\times T_{c}\times c$ time.

The scaled speedup would be:

$$
\text{SSpeedup}_{c} = \frac{S + T_{c} + P\times T_{c}\times c}{T_{c}} = S + P\times c
$$

We can see *the scaled speedup increases linearly with the number of compute units*.