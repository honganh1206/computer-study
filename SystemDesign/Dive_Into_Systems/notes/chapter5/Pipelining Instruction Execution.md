To execute a sequence of $N$ instructions it takes $4N$ clock cycles, and each instruction is executed once by the CPU

As each stage has a specific CPU circuitry active when that stage is executed, such circuitry will only actively involved *once* every four cycles. Example: The fetch circuitry during the Fetch stage will be used once and not in later stages.

But what if we can tell the fetch circuitry to *continue executing the Fetch parts of later instructions*? In that way the CPU can complete the execution of *more than one* instruction every four cycles

What is **CPU pipelining**? We start the execution of the next instruction *before the current instruction has completed its execution*. Example: When the 1st instruction enters the Decode stage, the 2nd instruction will enter the Fetch stage.

![[image-28.png|The CPU has reached the steady state of completing one instruction every cycle (circled red)]]

Pipelining increases **instruction throughput** aka the number of instructions the CPU can execute in a given period of time

While this improves the performance of microprocessors, this comes at the cost of 
- A more complicated CPU design
- Additional storage and control circuitry
- Multiple instruction registers

Different processors may have fewer or more pipeline stages. Example: Initial ARM architecture only has Fetch-Decode-Execute with the Execute stage performing both the ALU execution and WriteBack functionality