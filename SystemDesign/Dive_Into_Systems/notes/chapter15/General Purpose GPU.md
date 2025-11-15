**General Purpose GPU** (GPGPU) computing applies special-purpose GPU processors to general-purpose parallel computing tasks.

> Think of it like a combination of computation on CPU cores with SIMT computation on the GPU processors.

GPGPU computing performs best on parallel applications that can be constructed as a stream processing computation on a grid of multidimensional data (Dumber version: Excel at doing the same kind of work many times at once).

The OS does NOT manage the GPU's processors or memory (GPUs have their own memory), so we must copy the data from the computer's main memory to the GPU's memory before running GPU code, and we must *copy the results back* from the GPU to the CPU memory when we need to use it in CPU.

GPGPU programming languages and libraries often provide *abstractions* over managing GPU memory from the programmer. Example: A programmer can call CUDA library functions to allocate CUDA memory on the GPU and copy data between CUDA memory on the GPU and host memory.

## When GPGPUs shine

Since GPUs provide *limited support for thread synchronization*, GPGPU parallel computing performs particularly well for parallel applications that:

A. Embarrassingly parallel - no or almost no communication or synchronization between threads and processes.
B. Have large extent of independent parallel stream-based computation with very few synchronization points.

GPGPU computing also performs well when *there are few memory copies between host and device memory*.

In contrast, if GPU-CPU data transfer dominates execution time, or if an application requires fine-grained synchronization, GPGPU computing may not perform well.