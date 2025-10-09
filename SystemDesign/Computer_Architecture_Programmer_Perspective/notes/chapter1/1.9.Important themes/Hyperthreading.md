---
tags:
  - "#study"
cssclasses:
  - center-images
---
Hyperthreading allows *a single CPU/core to execute multiple flows of controls* i.e., [[Threads]]. In this case, we have **multiple copies of some of the CPU hardware** (program counters + register files) while we only have **single copies of other parts** (ALUs)

(Example): A multi-threaded video editing software with one thread *handling decoding* the frames and one thread *applying filters to such frames* => Hyperthreading allows *both threads to execute simultaneously on a single core*, thus better resource utilization.

[[A hyperthreaded processor allows cycle-by-cycle basis]]

When executing command like `lscpu`, the "CPU(s)" field indicates the number of **hyperthreaded (logical) cores**, not the number of physical cores.

> [!warning]
> Performance on hyperthreaded cores does not scale at the same rate as physical core.

If one task idles e.g., due to [[Control Hazards]], another task can use the core.

Hyperthreading is meant to *improve process throughput* i.e., the number of processes that complete in a given unit of time, not process speedup.