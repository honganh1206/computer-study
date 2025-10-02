#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void sigchld_handler(int signum) {
  int status;
  pid_t pid;

  // Reap all exited child processes,
  // and does NOT block if there are no zombie child processes to reap (WNOHANG flag).
  // As long as there is a valid PID value,
  // there will be child processes to reap.
  while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
    printf("[SIGCHLD] Reaped child with PID %d\n", pid);
  }
}

int main(void) {
  pid_t pid;
  // Register the SIGCHLD handler
  // so when a child exits, the handler is invoked.
  // This will execute whenever the parent receives a SIGCHLD signal
  // regardless of whether the parent is blocked on call to wait or waitpid.
  if (signal(SIGCHLD, sigchld_handler) == SIG_ERR) {
    perror("signal");
    exit(EXIT_FAILURE);
  }

  // Create child processes
  for (int i = 0; i < 3; i++) {
    pid = fork();
    if (pid < 0) {
      perror("fork");
      exit(EXIT_FAILURE);
    }

    if (pid == 0) {
      // Chid
      printf("Child %d started (PID=%d)\n", i, getpid());
      sleep(2 + i);
      printf("Child %d exiting (PID=%d)\n", i, getpid());
      exit(0);
    }
    // Parent continues after the call to waitpid
  }

  printf("Parent running (PID=%d)\n", getpid());

  // Infinite loop to simuate server-like behavior
  while(1) {
    printf("Parent is alive...\n");
    sleep(5);
  }

  return 0;
}
