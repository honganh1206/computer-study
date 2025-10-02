Explicit wait e.g., `wait` and `waitpid(pid, &status, 0)` means *the parent blocks until at least one child terminates*.

```c
pid_t pid = fork();
if (pid == 0) {
    exit(42); // child exits
} else {
    int status;
    wait(&status); // parent blocks here until child exits
    printf("Child exited with %d\n", WEXITSTATUS(status));
}
```

Non-blocking wait e.g., `waitpid(pid, &status, WNOHANG)` means the parent checks if a child has exited, and if not, the parent returns immediately instead of blocking.

Implicit wait e.g., `system("command")` creates a child with `fork` then *internally* calls `waitpid` to collect the result.