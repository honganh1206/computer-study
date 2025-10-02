When a child process terminates, the OS sends a `SIGCHLD` signal to its parent process (refer to [[Exit and Wait]])

In programs that create child processes, the parent process does NOT always want to block on a call to `wait` until its child processes exit. Instead, they let the signal handler code do it.

Example: The parent process can run in the foreground handling shell commands, while the child process runs in the background. After the child processes exit, the parent process needs to call `wait` to reap its zombie child processes (See [[Waiting, Blocking and Reaping]]) from hoarding resources. In such cases, the parent can register a *signal handler to `SIGCHLD` signals*, and that handler code will run and make calls to `wait` to reap its zombie children.

[[The family system calls of wait]]