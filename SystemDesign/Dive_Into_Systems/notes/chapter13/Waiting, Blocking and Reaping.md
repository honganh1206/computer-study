A parent process **reaps** (clean up the rest of the state) its zombie child by calling the `wait` system call. 

However, the parent process blocks (pause the execution and do nothing further) if the parent calls `wait` BEFORE its child process exits, and the parent then reaps the child process by calling `waitpid` with a PID argument of the child.

![[image-11.png|From left to right: The child process calls exit to clean up its execution state -> The parent receives a SIGCHILD signal -> The parent calls waitpid to reap its zombie child]]

> Since the parent and the child execute concurrently, the parent may call `wait` before its child exits or the child can exit before the parent calls `wait`

A programmer can design the parent process code so that it will *never* block waiting for a child process to exit. But how? If the parent implements a `SIGCHILD` signal handler that contains the call to `wait`, then the parent only calls `wait` when there is a exited child process to reap.

```bash
$  a.out        # shell process forks child and calls wait

$  a.out &      # shell process forks child but does not call wait
$  ps           # (the shell can run ps and a.out concurrently)
```

[[The family system calls of wait]]
