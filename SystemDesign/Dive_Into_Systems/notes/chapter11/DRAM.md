DRAM uses **capacitors** - electrical components that hold an electrical charge

It is dynamic because *it must frequently refresh the charge of its capacitors to maintain a stored value*

Modern systems use DRAM to implement main memory on modules that connect to the CPU. These modules are connected to the CPU via the *memory bus*

![[image-1.png|The positions of primary storage devices relative to the memory bus]]

To retrieve a value from memory, the CPU puts an address of the data on the memory bus + signal the memory modules to perform a read. After a short delay, the memory module sends the value at the address to the CPU via the bus.

Even though the CPU and main memory are physically a few inches away from each other, data still has to move through the memory bus when moving between the CPU and main memory. This extra distance increases the latency and reduces transfer rate, thus creating the *von Neumann bottleneck* (The CPU cannot access instructions and data simultaenously)