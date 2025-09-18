To terminate, the process calls the `exit` system call so the OS cleans up most of the process's state. After the child process runs the exit code, it notifies the parent process that it has exited, and the parent is responsible for cleaning up the exited child's remaining state from the system.

Processes can be triggered to exit in several ways:

- A process may complete all of its application code. When it returns from its `main` function, it invokes the `exit` system call
- A process can perform an invalid action e.g., dividing by zero, resulting in its exiting
- A process can receive a [[Signal]] from the OS telling it to exit. 

## How to exit, really?

A shell process can terminate its child process running `a.out` by sending a `SIGKILL` signal. When the child process receives the signal, it runs the signal handler code for `SIGKILL` that calls `exit`.

Similarly, when an user types `CTRL-C` in a Unix shell, the child process receives a `SIGINT` signal calling `exit`.

After executing `exit`, the OS delivers a `SIGCHILD` signal to the parent process to notify it that the child has exited and thus become a *zombie process* (its execution state is cleaned up, but the OS still maintains a little information about it)

[[Blocking and Reaping]]

Example of invoking multiple system calls:

```c
pid_t pid1, pid2, ret;
int status;

printf("A\n");

pid1 = fork();
if (pid1 == 0 ) {       /* child 1 */
    printf("B\n");

    pid2 = fork();
    if (pid2 == 0 ){    /* child 2 */
        printf("C\n");
        execvp("a.out", NULL);
    } else {            /* child 1 (parent of child 2) */
        ret = wait(&status);
        printf("D\n");
        exit(0);
    }
} else {                /* original parent */
    printf("E\n");
    ret = wait(&status);
    printf("F\n");
}
```

Execution timeline of the code above:

![[image-12.png|Solid lines represent dependencies in the order of execution, and dotted lines represent concurrent execution points]]

The parent process could call `wait` and block when its child process calls `fork` to create its child processes.