The OS creates a *copy* of the parent process's execution at the point when the parent calls `fork`

At the time of the fork, the child process inherits its execution state from its parent. This execution state includes the parent's address space contents, CPU register values, and the system resources like open files.

The OS also creates a new **process control struct**, an OS data structure for managing the child process.

After the OS creates and initializes the new child process, the child and parent are *concurrent*, meaning they both continue running and their executions overlap as the context switches them on and off the CPU.

When the child process is first scheduled to run on the CPU, it starts executing at the point its parent left off (as it has the copy of the parent's execution state),

After the call to `fork`, the parent and child execute in their separate execution contexts at the return point of the `fork` call. The return value of `fork` from the parent process is the child's PID, while for the child the return value is 0.

```c
pid_t pid;

pid = fork();   /* create a new child process */

print("pid = %d\n", pid);  /* both parent and child execute this */
```

![[image-7.png|Both processes assign the return value of fork to their PID variable]]

> Programmers often want the child and parent processes to perform different tasks after the fork call.

Depending on when each is scheduled to run on the CPU, either the parent or the child can execute statements before the other, or they could be interleaved.

![[image-9.png|Only the parent exists before the call to fork. After fork returns both processes run concurrently (shown in dotted lines)]]