#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mpi.h"

#define ARRAY_SIZE (40)
#define SCALAR (10)

/* In a real application, the boss process would read its input from a data file */
int *build_arr(int *arr_size) {
	int i;
	int *result = malloc(ARRAY_SIZE * sizeof(int));

	if (result == NULL) {
		exit(1);
	}

	for (i = 0; i < ARRAY_SIZE; i++) {
		result[i] = i;
	}

	*arr_size = ARRAY_SIZE;
    return result;
}

/* Print the elements of an array, given the array and its size. */
void print_array(int *array, int array_size) {
    int i;
    for (i = 0; i < array_size; i++) {
        printf("%3d ", array[i]);
    }
    printf("\n\n");
}

/* Multiply each element of an array by a scalar value. */
void scalar_multiply(int *array, int array_size, int scalar) {
    int i;
    for (i = 0; i < array_size; i++) {
        array[i] = array[i] * scalar;
    }
}

int main(int argc, char **argv) {
	int rank, process_count;
	int array_size, local_size;
	int scalar;
	int *array, *local_array;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &process_count);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	/* Design rank 0 to be boss process.
	 * It generates input array and chooses the scalar */
	if (rank == 0) {
		array = build_arr(&array_size);
		scalar = SCALAR;
		printf("Initial array:\n");
        print_array(array, array_size);
	}

	/* Send one integer MPI_INT? starting from address of scalar var from the process of rank 0
	 * to every other processes via MPI_COMM_WORLD
	 * Workers of non-zero ranks receive the broadcast result (scalar value) into their local arrays*/
	MPI_Bcast(&scalar, 1, MPI_INT, 0, MPI_COMM_WORLD);

	/*Boss process sends the total array size to worker processes and they receive it */
	MPI_Bcast(&array_size, 1, MPI_INT, 0, MPI_COMM_WORLD);

	/*Determine how many array elements each array gets
	 * Assuming the elements are equally distributed by the number of processes
	 * For example: If the input array contains 40 elements and the application consists of 8 processes
	 * then each process is responsible for five elements */
	local_size = array_size / process_count;

	local_array = malloc(local_size * sizeof(int));
	if (local_array == NULL) {
		exit(1);
	}

	/*Scatter chunks of arrays evenly among processes.
	 * Underneath? The boss process (rank == 0) calls MPI_Send and worker processes call MPI_Recv.
	 * MPI_Recv underneath is a BLOCKING call, meaning the process that calls it will pause
	 * until it receives data (Just like how channels and buffers work in Go).
	 * Interesting: This function uses buffers underneath
	 * This might be to pack data into a contiguous form, avoid race conditions, protocol alignment etc.*/
	MPI_Scatter(array, local_size, MPI_INT, local_array, local_size, MPI_INT, 0, MPI_COMM_WORLD); 

	scalar_multiply(local_array, local_size, scalar);

	/*Boss process (rank == 0) gathers chunks by calling MPI_Recv from all worker processes calling MPI_Send
	 * and coalesces the results into a single array*/
	MPI_Gather(local_array, local_size, MPI_INT, array, local_size, MPI_INT, 0, MPI_COMM_WORLD);

    /* Boss prints the final answer. */
    if (rank == 0) {
        printf("Final array:\n");
        print_array(array, array_size);
    }

    /* Clean up. */
    if (rank == 0) {
        free(array);
    }
    free(local_array);
    MPI_Finalize();

    return 0;

}
