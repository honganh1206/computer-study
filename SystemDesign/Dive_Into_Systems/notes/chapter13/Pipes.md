A *one-way* communication channel for processes running on the same machine.

Pipes are commonly used in shell commands to send output from one process to the input of another process.

```bash
# cat processes output of foo.c
# then grep searches for the string "factorial" in the output of cat
cat foo.c | grep factorial
```

The bash shell process first calls the `pipe` system call to request the OS to create a pipe communication, and the pipe will be used by `cat` and `grep`.

The shell program sets up the `stdout` of `cat` to write to the write end of the pipe, and also sets up the `stdin` to read from the read end of `grep`

![[image-24.png|Pipes as unidirectional communication channels]]

