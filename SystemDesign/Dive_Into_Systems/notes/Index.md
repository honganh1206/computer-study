---
id: Index
aliases: []
tags: []
---

[Web version!](https://diveintosystems.org/)

# Index of Dive Into Systems

[[Chapter 0 - Introduction]]

[[Chapter 1 - Introduction to C programming]]

C programming basics like compiling and running

[[Chapter 2 - A deeper dive into C programming]]

**Most** of the C language, notably pointers and dynamic memory

[[Chapter 3 - C Debugging Tools]]

- Common C debugging tools like GDB and Valgrind
- Illustrate how they can be used to **debug various applications**

[[Chapter 4 - Binary and Data Representation]]

- Encoding data into binary
- Binary representation of C types
- Arithmetic operations on binary data
- Arithmetic overflow

[[Chapter 5 - What Von Neumann knew Computer Architecture]]

- Von Neumann architecture from logic gates to the construction of a basic CPU
- Clock-driven execution
- Stages of instruction execution through arithmetic, storage and control circuits
- (Briefly) Pipelining, modern architecture features

[[Chapter 6 - Under the C Diving into Assembly]]

Translating C into assembly code from basic arithmetic expressions to functions, stackks, and arrays and `struct`

[[Chapter 7 - 64-bit x86 Assembly]]

[Chapter 8 - 32-bit x86 Assembly (IA32)](url)

[Chapter 9 - ARM Assembly](url)

[[Chapter 10 - Key Assembly Takeaways]]

[[Chapter 11 - Storage and the Memory Hierarchy]]

- Storage devices
- The memory hierarchy and its effects on performance, locality and caching
- Cachegrind profiling tool

[[Chapter 12 - Code Optimization]]

- Compiler optimizations
- Design applications with performance in mind
- Tips for code optimization
- Quantitative measurement of a program's performance

[[Chapter 13 - The Operating System]]

Core OS abstractions and mechanisms like processes, virtual memory and interprocess communication

[[Chapter 14 - Leveraging Shared Memory in the Multicore Era]]

- Multicore processors
- Threads and Pthreads programming
- Synchronization
- Race conditions
- Deadlock
- Advanced topics: Measuring parallel performance, thread safety, and cache coherence

[Chapter 15 - Looking ahead](url)

- Intro to distributed memory systems and Message Passing Interface (MPI)
- Hardware accelerators and CUDA
- Cloud computing
- MapReduce

## Chapter Ordering

### Intermediate-level courses

- [ ] Flow 1: 4 -> 1/3 -> 5 -> 6 -> 7 --> 10 -> 2/3 -> 11 -> 13 -> 14

- [x] Flow 2: 1 -> 4 -> 2/3 ->6 -> 7 -> 10 to 15

### Uper-level courses / Background reading

| Topic                            | Chapters for background reading |
| -------------------------------- | ------------------------------- |
| Architecture                     | 5, 11                           |
| Compilers                        | 6 to 12                         |
| Database systems                 | 11, 14 ,15                      |
| Networking                       | 4, 13 14                        |
| OS                               | 11, 13 ,14                      |
| Parallel and distributed systems | 11, 13, 14, 15                  |
