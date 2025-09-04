#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

// Helper function to compute wall clock time
double getTime(struct timeval ts, struct timeval te) {
    double time = te.tv_sec - ts.tv_sec + (te.tv_usec - ts.tv_sec)/1.e6;
    return time;
}

int * allocateArray(int len) {
    int * result = malloc(len * sizeof(int));
    return result;
}
//helper function: prints out elements of array separated by spaces
void printArray(int * arr, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int isPrime(int x) {
    int i;
    for (i = 2; i < sqrt(x)+1; i++) {
        if (x % i == 0) {
            return 0;
        }
    }

    return 1;
}

int getNextPrime(int prev) {
    int next = prev + 1;
    while (!isPrime(next)) {
        // Increment to the next check if not prime
        next++;
    }
    return next;
}

int genPrimeSequence(int *arr, int limit) {
    int i;
    int len = limit;
    if (len == 0) return 0;
    arr[0] = 2;
    for (i = 1; i < len; i++) {
        arr[i] = getNextPrime(arr[i-1]);
        if (arr[i] > limit) {
            len = i;
            return len;
        }
    }
    return len;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <num>\n", argv[0]);
        printf("where <num> is upper limit of the desired range of primes\n");
        return 1;
    }
    struct timeval tstart, tend;
    int limit = strtol(argv[1], NULL, 10);
    gettimeofday(&tstart, NULL);
    int * array = allocateArray(limit); //array can't be longer than the limit size
    //gettimeofday(&tend, NULL);
    //printf("Time to allocate: %g\n", getTime(tstart, tend));

    //gettimeofday(&tstart, NULL);
    int length = genPrimeSequence(array, limit);
    gettimeofday(&tend, NULL);
    printf("Time to generate primes: %g\n", getTime(tstart, tend));
    printf("%d primes found.\n", length);
    //printf("The first %ld prime numbers are:\n", limit);
    //printArray(array, length);
    return 0;
}
