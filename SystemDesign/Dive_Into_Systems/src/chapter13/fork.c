#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  pid_t pid, mypid;

  printf("A\n");
  pid = fork(); // Create a child process

  if (pid == -1) {
    printf("fork failed\n");
    exit(pid);
  }

  if (pid == 0) {
    mypid = getpid();
    printf("Child: fork returned %d, my pid: %d\n", pid, mypid);
  } else {
				mypid = getpid();

    printf("Parent: fork returned %d, my pid: %d\n", pid, mypid);
		}




}
