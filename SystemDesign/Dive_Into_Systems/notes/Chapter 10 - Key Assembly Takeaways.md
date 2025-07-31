The [[Instruction Set Architecture]] defines the Assembly language. We can use the `uname -m` command to identify the underlying architecture

[[Registers]] hold data. Some are general (can store any kind of data) and some are for specific uses like storing pointers. Some can even be read-only e.g., instruction pointer

The program [[Stack]] holds local variables associated with a particular function. 

The program stack grows toward *lower memory addresses*.

The compiler uses the [[Stack pointer and frame pointer]] to specify a [[Stack frame and frame record]] to define an area associated with a particular function or procedure.

When a function ends, the stack and base pointers return to their original value as a bookkeeping mechanism. However, old data can sometimes stick around, and attackers can abuse that to create exploits like [[Buffer overflow in x86-64 ISA]]