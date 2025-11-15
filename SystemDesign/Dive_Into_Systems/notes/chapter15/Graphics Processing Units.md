GPUs perform computer graphics computations, operating on image data to enable high-speed graphics rendering and image processing.

A GPU writes its results to a frame buffer, which delivers the data to the computer's display.

## Architecture Overview

GPUs use the *single instruction/multiple thread* ([[SIMT]]), a variation of SIMD, as the hardware execution model.

![[image-1.png]]

NVIDIA GPUs consist of several *streaming multiprocessors* (SMs), and each of them has its own execution control units (processing cores), scheduler, and memory space (registers, L1 cache, shared memory).

Each SM has several *scalar processor* (SP) cores.

The SM includes a *warp scheduler* that schedule **warps** (sets of application threads for example 32 threads) to execute in lockstep on its SP cores.

## How it works

In lockstep execution, each thread in a warp executes the same instruction each cycle *but on different data*. 

Example: If an application is changing a color image to grayscale, *each thread in a warp executes the same sequence of instructions at the same time* to set a pixel's RGB value to its grayscale equivalent. That is, each thread in the warp executes the instructions on a different pixel data value, meaning multiple pixels of the image are updated *in parallel*.

Since the threads are executed in lockstep, the processor design can be *simplified* so multiple cores share the same instruction control units (no need for per-thread instruction control).

[[General Purpose GPU]]


> [!information] Why don't we replace CPUs with GPUs?
> CPUs and GPUs are designed for very different kinds of work. Think of CPUs as *skilled craftsmen* who can handle complex, irregular jobs, while GPUs as *factory* where identical items are massed produced.

| Feature             | CPU                                                                    | GPU                                                 |
| ------------------- | ---------------------------------------------------------------------- | --------------------------------------------------- |
| **Goal**            | Low-latency execution of a few complex tasks                           | High-throughput execution of many simple tasks      |
| **Control**         | Sophisticated control logic, branch prediction, out-of-order execution | Simple control, executes threads in lockstep (SIMT) |
| **Thread behavior** | Few, independent threads                                               | Thousands of threads, mostly identical              |
| **Best for**        | Sequential, decision-heavy code                                        | Repetitive, data-parallel workloads                 |

> [!information] Why are GPUs favored for training AI models?
> GPUs' architecture is optimized for *massively parallel numeric computation*, which aligns perfectly with the structure of neural network operations. Having thousands of smaller cores to handle repetitive linear algebra operations independently and concurrently helps a lot.