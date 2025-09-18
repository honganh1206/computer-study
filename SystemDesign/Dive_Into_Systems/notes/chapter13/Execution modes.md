As the OS is also software, it must *protect its code and state from regular processes*. For that reason, the CPU helps by defining two execution modes:

1. User mode (When user-level programs run on the CPU): The CPU only executes *user-level instructions* and accesses memory locations the OS makes available. The CPU cannot access the OS's instructions and data.
2. Kernel mode (When OS code runs on the CPU): A CPU can execute *any* instructions and access *any* memory location. The CPU can access hardware components and execute special instructions.

If the CPU is in user mode and receives an interrupt, it switches to kernel mode and executes OS code. When the OS is done handling the interrupt, it restores the CPU state to continue executing user-level code at the point of the switch.

![[image-4.png|User code runs on the CPU at time X, then OS interrupt handler code runs. After that, user code is resumed at time Y]]

