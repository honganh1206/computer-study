---
tags:
  - "#study"
cssclasses:
  - center-images
---
> The OS keeps track of all the state information the process needs to run (context)

A uniprocessor system can only execute the code from a **single** process at any point of time. 

When the OS needs to transfer control from one process to another, it *performs a context switching* by saving the context of the current one → restoring the context of the new process → passing the control => The new process picks up exactly where it left off


![[Pasted image 20240913182413.png]]

## How the shell program and the `hello` program work together

Initially, the shell program is running alone, waiting for input 
→ When we want to run the `hello` program, the shell invokes a **system call** that passes control to the OS 
→ The OS saves the shell process’s context + creates a new `hello` process + passes control to the new process
→ After the `hello` process is done, the control is passed back to the shell process

[[The transition from one process to another is managed by the kernel]]