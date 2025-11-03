#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>

#define MAX 10 //the maximum value of an element. (10 means 0-9)
pthread_mutex_t mutex;

/*error handling function: prints out error message*/
int print_error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(2);
}

/*helper function:fillString
/*fills the string pointed to by string with random digits
 *separated by spaces.
*/
void fillString(char *string, long length) {
    long i;
    for (i = 0; i < length; i += 2) {
        string[i] = (rand() % 10) + 49;
        string[i + 1] = 32;
    }
    string[length-1]=0;
}

/*helper function: printCounts
 * prints out all the values in the counts array, separated by spaces
*/
void printCounts(int *counts) {
    int i;
    for (i = 0; i < MAX; i++) {
        printf("%d ", counts[i]);
    }
    printf("\n");
}

struct t_arg{
    long id; //thread's id
    int *counts_ptr; //pointer to counts
    char *str_ptr; //pointer to string
    long length;
    long nthreads;
};

/* computes the frequency of all the elements in the input string and stores
 * the associated counts of each element in the array called counts
*/
void *countElemsStr(void *args) {
    struct t_arg *myargs = (struct t_arg *)args;
    long myid = myargs->id;
    char *input_str = myargs->str_ptr;
    int *counts = myargs->counts_ptr;
    long total_length = myargs->length;
    long numthreads = myargs->nthreads;

    int val, i;
    char *token;
    int local_counts[MAX] = {0};
    char *save_ptr; // Save state of strtok_r

    // compute LOCAL start and end values and chunk size
    long chunk = total_length / numthreads;
    long start = myid * chunk;
    long end = (myid + 1) * chunk;
    if (input_str[start] <= '0') {
        start++; // ensure we start on a number. Less than 0 means a space/punctuation/control char
    }
    if (input_str[end] >= '0') {
        end--; // ensure we end on a space
    }
    input_str[end] = 0; // ending point for parsing

    // tokenize values thread-safe
    token = strtok_r(input_str, " ", &save_ptr);
    while (token != NULL) {
        val = atoi(token);
        local_counts[val] =local_counts[val] + 1;
        token = strtok_r(NULL, " ", &save_ptr);
    }

    pthread_mutex_lock(&mutex);
    for (i = 0; i < MAX; i++) {
        counts[i] += local_counts[i];
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}


/* main function:
 * calls countElemsStr on a static string and counts up all the digits in
 * that string.
*/
int main(int argc, char **argv) {

    if (argc != 4) { //checks to ensure we have the correct number of args
        fprintf(stderr, "usage: %s <n> <p?> <t>\n", argv[0]);
        fprintf(stderr, "where <n> is the number of digits in the string and\n");
        fprintf(stderr, "<p?> is a binary value (0/1) indicating if counts");
        fprintf(stderr, "should be printed\n");
        fprintf(stderr, "<t> is the number of threads\n");
        return 1;
    }
    int ret;
    int verbose = atoi(argv[2]);
    long nthreads = strtol(argv[3], NULL, 10);
    if (nthreads < 1) print_error("ERROR: nthreads must enter a positive length");
    long length = strtol(argv[1], NULL, 10);
    if (length < nthreads) print_error("ERROR: length must be greater than nthreads");

    //seed random number generator with static value
    srand(10);
    ret = pthread_mutex_init(&mutex, NULL);
    if (ret) print_error("ERROR: pthread_mutex_init failed");

    //fill string with n digits
    char *inputString = malloc(length * 2 * sizeof(char));
    if (!inputString) print_error("ERROR: malloc failed");
    fillString(inputString, length * 2);

    //allocate counts array.
    int counts[MAX] = {0};
    pthread_t *thread_arr = malloc(nthreads * sizeof(pthread_t));
    struct t_arg *thread_args = malloc(nthreads * sizeof(struct t_arg));
    if (!thread_arr || !thread_args) print_error("ERROR: malloc failed");
    long t;
    //fill t_args
    for (t = 0; t < nthreads; t++) {
        thread_args[t].id = t;
        thread_args[t].counts_ptr = counts;
        thread_args[t].str_ptr = inputString;
        thread_args[t].length = length * 2;
        thread_args[t].nthreads = nthreads;
    }

    //print out array before sort
    if (verbose == 2) {
        printf("original string:\n");
        printf("%s\n", inputString);
    }

    //print out array before sort
    if (verbose > 1) {
        printf("original string:\n");
        printf("%s\n", inputString);
    }
    for (t = 0; t < nthreads; t++) {
        ret = pthread_create( &thread_arr[t], NULL, countElemsStr, &thread_args[t] );
        if (ret) print_error("ERROR: pthread_create failed");
    }
    for (t = 0; t < nthreads; t++) {
        ret = pthread_join(thread_arr[t], NULL);
        if (ret) print_error("ERROR: pthread_create failed");
    }
    //print out array after sort
    if (verbose) {
        printf("contents of counts array:\n");
        printCounts(counts);
    }

    //clean up
    pthread_mutex_destroy(&mutex);
    free(thread_arr);
    free(thread_args);
    free(inputString);

    return 0;
}
