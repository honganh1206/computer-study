#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_ITERATIONS 5

sem_t sem;
// Shared resource between threads
int shared_counter = 0;

/*error handling function: prints out error message*/
int print_error(char *msg) {
  fprintf(stderr, "%s\n", msg);
  // Custom error. Use 1 or EXIT_FAILURE as default.
  exit(2);
}

void *producer(void *arg) {
  for (int i = 0; i < NUM_ITERATIONS; i++) {
    sleep(1); // Simulate work?
    shared_counter++;
    printf("[Producer] Incremented counter to %d\n", shared_counter);

    // Signal the semaphore to wake the consumer
    sem_post(&sem);
  }
  return NULL;
}

void *consumer(void *arg) {
  for (int i = 0; i < NUM_ITERATIONS; i++) {
    // Wait until producer signals
    sem_wait(&sem);
    printf("[Consumer] Observed counter = %d\n", shared_counter);
  }
  return NULL;
}

int main() {
  pthread_t prod_thread, cons_thread;
  int ret;
  
  if (sem_init(&sem, 0, 0) != 0)  {
    print_error("sem_init failed");
  }

  if (pthread_create(&prod_thread, NULL, producer, NULL) != 0) {
      print_error("Failed to create producer thread");
  }

  if (pthread_create(&cons_thread, NULL,consumer, NULL) != 0 ){
    print_error("Failed to create consumer thread");
  }

  ret = pthread_join(prod_thread, NULL);
  if (ret)
    print_error("pthread_join for producer thread failed");

  ret = pthread_join(cons_thread, NULL);
  if (ret)
    print_error("pthread_join for consumer thread failed");

  sem_destroy(&sem);
  return 0;
}
