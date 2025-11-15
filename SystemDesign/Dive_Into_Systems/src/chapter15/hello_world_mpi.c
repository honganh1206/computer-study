#include <stdio.h>
#include <unistd.h>
#include "mpi.h"

// MPI simultaneously executes multiple copies of this program as independent processes across one or more computers
// Each process makes call to MPI to determine how many total processes are executing and which process it is
int main(int argc, char **argv) {
		int rank, process_count;
		char hostname[1024];

		MPI_Init(&argc, &argv);

		// Determine number of processes
		MPI_Comm_size(MPI_COMM_WORLD, &process_count);
		// Determine which process is running
		MPI_Comm_size(MPI_COMM_WORLD, &rank);

		// Determine machine host name running this
		gethostname(hostname, 1024);

		printf("Hello from %s process %d of %d\n", hostname, rank, process_count);

		MPI_Finalize();
		return 0;
}

// Compile: mpicc -o hello_world_mpi hello_world_mpi.c
// Run: mpirun -np 8 --hostfile hosts.txt (specifying number of processes per node) ./hello_world_mpi
