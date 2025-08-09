Locality is one of the common memory access patterns. Designers build hardware that exploits good locality to *automatically move data into an appropriate storage location*.

A system improves performance by *moving the subset of data a program is using into the storage that is closer to the CPU*. As more necessary data moves up the memory hierarchy, unused data moves farther from it.

 > Building hardware that exploits locality is an *abstraction problem*. We the programmers should be aware of this to achieve good performance.

Two kinds of locality: [[Temporal locality]] and [[Spatial locality]]

[[From Locality to Caches]]
