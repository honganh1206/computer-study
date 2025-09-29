After the booting, the OS waits to do something, as many OSes are **interrupt-driven systems** - the OS does not run/in sleep mode until an entity needs it to do something.

## OS Interrupts

Devices need the OS to do something for them. A **network interface card** (NIC) can wake the OS up to handle received data over its network connection. In that case, the OS delivers the data from the NIC to the waiting web browser process.

![[01-Areas/Computer/SystemDesign/Dive_Into_Systems/notes/chapter13/image-2.png]]

When the NIC receives data from the network, it is referred to as **interrupts**. 

Hardware interrupts are delivered to the CPU on an *interrupt bus*.

How it goes: A device places a number indicating the type of interrupt on the bus. When the CPU detects the signal, it stops executing the current process's instructions and starts executing OS interrupt handler code. After the execution, the OS resumes to the process's instructions at the point where the interruption occurs.

![[01-Areas/Computer/SystemDesign/Dive_Into_Systems/notes/chapter13/image-3.png]]


## OS Traps

Requests to the US can also come from user applications. When an application writes to a file, it makes a [[System call]] to the OS to perform write on its behalf. This is referred to as **traps**

[[Execution modes]]

*Interrupts can happen at any time*, meaning the OS can switch from running user code to interrupt handler code at *any machine cycle*. To efficiently manage this, we allow the kernel to *run within the execution context of every process* in the system.

At boot time, the OS loads its code at a *fixed location* in RAM, and that location is mapped into the *top of the address space of every process* i.e., every process has its top address pointing to the OS code.

![[image-5.png]]

We also initialize a CPU register with the starting address of the OS handler function. On an interrupt, the CPU executes the OS interrupt handler functions at the top of every process' address space. In that way , the handle code can execute quickly *in the context of any process*.

> This OS code can be accessed only in kernel mode.

> [!warning]
> Many modern processors have features that expose vulnerabilities to kernel protections when the OS is mapped into the top of every process' address space. The [Meltdown hardware exploit](https://meltdownattack.com/) is an example of this.

