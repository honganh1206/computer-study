Tags: #review 

A **signal** is a *software interrupt* sent by one process to another via the OS.

When a process receives a signal, it's execution is interrupted by the OS to *run signal handler code* and the execution continues when the signal handler returns. However, sometimes the signal handler causes the process to exit and not continue its execution point.

> [!imporntant]
> Signals are quite similar to hardware interrupt and traps, but also are different from both. A trap is a synchronous software interrupt when a process invokes a system call, but *all signals are asynchronous*. Also, signals are software-made and not hardware-made.

A process can send the `kill` system call as a signal to another process. The OS can also uses signals to notify processes of certain events e.g., `SIGCHILD`

> [!info]
> Signals define a *fixed* number of signals e.g., Linux defines 32 different signals, so signals provide a *limited* way processes can communicate with each other.

When a process receives a signal, one of these actions can occur:

1. The process can terminate
2. The signal can be ignored
3. The process can be blocked
4. The process can be unblocked

The OS defines a default action and supplies the default signal handler code for every signal number, but *programmers can change the default action and write their own signal handler code*. However, for some signals, the OS-defined default actions CANNOT be overridden e.g., When receiving `SIGKILL` the OS will always force the process to exit.

Linux has `sigaction` and `signal` system calls to change the default behavior of a signal or register a signal handler to a particular signal.

[[Writing a SIGCHLD handler]]

