Primary storage devices consist of *random access memory* (RAM) - the time it takes to access data that is *not affected by the data's location in the device*

 RAM doesn't need to worry about moving parts into the correct positions or rewinding tape spools like HDDs.

Primary Storage Device Characteristics (2020):

| Device      | Capacity         | Approx. latency | RAM type |
| ----------- | ---------------- | --------------- | -------- |
| Register    | 4 - 8 bytes      | < 1 ns          | SRAM     |
| CPU cache   | 1 - 32 megabytes | 5 ns            | SRAM     |
| Main memory | 4 - 64 gigabytes | 100 ns          | DRAM     |

We have *static RAM ([[SRAM]])* and *dynamic RAM ([[DRAM]])* and [[CPU cache]]

Real systems incorportate *multiple levels of caches*. A CPU might have a very small and fast L1 cache that stores a subset of a slightly larger and slower L2 cache, and so on.