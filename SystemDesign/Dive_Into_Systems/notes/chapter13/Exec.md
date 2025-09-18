An `exec` system call tells the OS to *overwrite* the calling process's address space contents with the specified `a.out` and to *re-initialize* its execution state

```c
// filename specifies the name of the binary executable program
// to initialize the process's image
// argv contains the command-line arguments to pass into main function
int execvp(char *filename, char *argv[]);
```

Example:

```c
pid_t pid;
int  ret;
char *argv[2];

argv[0] = "a.out";  // initialize command line arguments for main
argv[1] = NULL;

pid = fork();
if (pid == 0) { /* child process */
	// Replace with a.out and initialize the child process to run a.out from the beginning
    ret = execvp("a.out", argv); 
	// At this point the execution continues in the child process
	// so if the call to execvp is successful, the following code will not be executed
	printf("Error: execvp returned!!!\n"); /* only executed if execvp fails */ exit(ret);
}
```

![[image-10.png|The OS replaces its image with a.out and re-initializes the child process to start running a.out from its beginning]]

