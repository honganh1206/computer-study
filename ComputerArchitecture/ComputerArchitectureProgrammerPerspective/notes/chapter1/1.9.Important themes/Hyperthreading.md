---
tags:
  - "#study"
cssclasses:
  - center-images
---
Hyperthreading allows *a single CPU/core to execute multiple flows of controls*. In this case, we have **multiple copies of some of the CPU hardware** (program counters + register files) while we only have **single copies of other pars** (ALUs)

(Example): A multi-threaded video editing software with one thread *handling decoding* the frames and one thread *applying filters to such frames* => Hyperthreading allows *both threads to execute simultaneously on a single core*, thus better resource utilization.

[[A hyperthreaded processor allows cycle-by-cycle basis]]