The code that acts as a layer between the kernel and the hardware.

There are two ways to interact with the hardware: Memory-mapped I/O and I/O ports.

If we use memory-mapped I/O, we can write to a specific memory address and the hardware will be updated with the new data.

If the hardware uses I/O ports then the assembly code instructions `out(port, data)` and `in(port)` must be used to communicate with the hardware