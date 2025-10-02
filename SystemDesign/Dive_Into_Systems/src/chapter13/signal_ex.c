#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// Handler for SIGALRM
void sigalarm_handler(int sig) {
  printf("BEEP, signal number: %d\n", sig);
  fflush(stdout);
  alarm(5); // Send another SIGALRM in 5 secs
}
/* signal handler for SIGCONT */
void sigcont_handler(int sig) {
  printf("in sigcont handler function, signal number %d\n.", sig);
  fflush(stdout);
}

/* signal handler for SIGINT */
void sigint_handler(int sig) {
  printf("in sigint handler function, signal number %d...exiting\n.", sig);
  fflush(stdout);
  exit(0);
}

int main(void) {
  /* Register signal handlers. */
  if (signal(SIGCONT, sigcont_handler) == SIG_ERR) {
    printf("Error call to signal, SIGCONT\n");
    exit(1);
  }

  if (signal(SIGINT, sigint_handler) == SIG_ERR) {
    printf("Error call to signal, SIGINT\n");
    exit(1);
  }

  if (signal(SIGALRM, sigalarm_handler) == SIG_ERR) {
    printf("Error call to signal, SIGALRM\n");
    exit(1);
  }
  printf("kill -CONT %d to send SIGCONT\n", getpid());
  alarm(5);
  while (1) {
    pause(); // Wait for a signal to happen
  }
}
