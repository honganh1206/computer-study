The OS can swap process state on the CPU as the primary mechanism behind [[Timesharing]]. There are two steps involved:

1. The OS *saves* the context of the current process running on the CPU including all of its register values , memory state and some other state.
2. The OS *restores* the saved context on the CPU and starts the CPU running this other process, continuing its execution where the it left off.

> [!question] A little paradox
> The context-switching code need to use CPU hardware registers to execute, but the register values from the process being context switched off the CPU need to be saved by the context-switching code.

How is the interrupted process's execution state saved? 

At boot time, the OS initialized the CPU state, so when the CPU switches to kernel mode during an interrupt, the OS interrupt handler code starts executing but *the interrupted process's execution state is protected from this execution*. 

-> Together, the computer hardware and the OS perform *some initial saving* of the user-level execution context. That saving is enough so the OS code can run on the CPU without losing the execution state of the interrupted process.

Example: Register values of the interrupted process need to be saved so the recovered process can continue from where it left off. Depending on the hardware support, saving the user-level process' register values can be done either by the hardware or the software. At a minimum the *process' program counter (PC)* value needs to be saved.

Scenario: A process is running on the CPU. 

When the OS starts running, it executes context switching code that can saves/restores the full execution state of the process. 

-> Since the OS runs in kernel mode, the context-switching code can save the CPU execution state of *any* process to memory. The context-switching code completes by setting up the CPU to execute the restored process' execution state + switch the CPU to user mode.