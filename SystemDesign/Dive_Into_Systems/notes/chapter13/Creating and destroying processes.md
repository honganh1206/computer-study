## Create a process

When to create? An OS creates a new process when an existing process makes a system call requesting it to do so. The result is a [[Process hierarchy]]

In Unix, the [[Fork]] system call creates a new process. The process calling `fork` is a *parent process* and the created process is a *child process*

Example: When we run `a.out` in a shell, the shell (parent process) requests the OS to create a process for `a.out` (child process) by calling the `fork` system call.

[[Exec]]

[[Exit and Wait]]

