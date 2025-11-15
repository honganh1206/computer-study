> [!summary]
> Each CUDA thread block is run by a GPU SM unit. An SM schedules a warp of threads to run its processor cores. All threads in a warp execute the same set of instructions in lockstep on different data (SIMT/SIMD). Threads share the instruction pipeline but get their own registers and stack space for local variables and parameters.

A **CUDA thread** is the basic execution unit in a CUDA program. CUDA threads are *scheduled in warps* that execute in lockstep on the GPU's SMs, and the SMs executing CUDA kernel code on their part of data stored in GPU memory.

CUDA threads are organized into *blocks*, and the blocks are organized into a *grid*.

Grids can be organized into one-, two- or three-dimensional groupings of blocks, and blocks can be organized into one-, two- or three-dimensional groupings of threads.

```c
dim3 blockDim(16,16);  // 256 threads per block, in a 16x16 2D arrangement
dim3 gridDim(20,20);   // 400 blocks per grid, in a 20x20 2D arrangement

// Call to a kernel function specifying grid and block layout
ret = do_something<<<gridDim,blockDim>>>(dev_array, 100);
```

## CUDA thread model

![[image-2.png|A grid of blocks of threads. 3x2 blocks per grid, and each block has a 2D set of threads, 4x3 threads per block]]

## Coordinating threads

```c
// threadId.x and threadId.y coordinate a thread in its containing block
// and blockIdx.x and blockIdy.y coordinate the thread's containing block in the grid
// x-axis being horizontal and y-axis vertical
int row = blockIdx.y * blockDim.y + threadIdx.y;
int col = blockIdx.x * blockDim.x + threadIdx.x;
```

## Example: Scalar multiply in CUDA

```c
x = a * x; // x is a vector and a is a scalar value
```

When run, the main function of this program will do the following:

1. Allocate host-side memory for vector `x` and initialize it
2. Allocate device/GPU?-side memory for vector `x` and copy it from host memory to GPU memory
3. Invoke CUDA kernel function to *perform scalar multiply in parallel*, with arguments as device address of vector `x` and scalar value `a`
4. Copy the result from GPU memory to host memory vector `x`

```c
#include <cuda.h>

#define BLOCK_SIZE       64     /* threads per block */
#define N              10240    /* vector size */

// some host-side init function
void init_array(int *vector, int size, int step);


// host-side function: main
int main(int argc, char **argv) {

  int *vector, *dev_vector, scalar;

  scalar = 3;     // init scalar to some default value
  if(argc == 2) { // get scalar's value from a command line argument
    scalar = atoi(argv[1]);
  }

  // 1. allocate host memory space for the vector (missing error handling)
  vector = (int *)malloc(sizeof(int)*N);

  // initialize vector in host memory
  // (a user-defined initialization function not listed here)
  init_array(vector, N, 7);

  // 2. allocate GPU device memory for vector (missing error handling)
  cudaMalloc(&dev_vector, sizeof(int)*N);

  // 2. copy host vector to device memory (missing error handling)
  cudaMemcpy(dev_vector, vector, sizeof(int)*N, cudaMemcpyHostToDevice);

  // 3. call the CUDA scalar_multiply kernel
  // specify the 1D layout for blocks/grid (N/BLOCK_SIZE)
  //    and the 1D layout for threads/block (BLOCK_SIZE)
  // Each CUDA thread executes this kernel function
  scalar_multiply<<<(N/BLOCK_SIZE), BLOCK_SIZE>>>(dev_vector, scalar);

  // 4. copy device vector to host memory (missing error handling)
  cudaMemcpy(vector, dev_vector, sizeof(int)*N, cudaMemcpyDeviceToHost);

  // ...(do something on the host with the result copied into vector)

  // free allocated memory space on host and GPU
  cudaFree(dev_vector);
  free(vector);

  return 0;
}
```

When a CUDA thread executes the CUDA kernel function, it goes through two steps:

1. The thread determines which portion of data it is responsible for based on its position in the GPU's grid
2. The calling thread performs application-specific computation on its assigned portion of data

```c
/*
 * CUDA kernel function that performs scalar multiply
 * of a vector on the GPU device
 *
 * This assumes that there are enough threads to associate
 * each array[i] element with a signal thread
 * (in general, each thread would be responsible for a set of data elements)
 */
__global__ void scalar_multiply(int *array, int scalar) {

  int index;

  // compute the calling thread's index value based on
  // its position in the enclosing block and grid
  index = blockIdx.x * blockDim.x + threadIdx.x;

  // the thread's uses its index value is to
  // perform scalar multiply on its array element
  // Each thread is responsible for computing scalar multiplication on exactly one element in the array
  array[index] = array[index] * scalar;
}
```

## Scheduling and Synchronization

Increasing the threads per block increases the degree of parallel execution.

Thread count should be a multiple of warp size: If not, the last warp becomes *partially filled* and the remaining thread slots are wasted.

Small multiples of SM cores work well: Since the SM can schedule warps in batches and run them concurrently, the pipeline is kept full, there are enough threads to keep the SM busy while the register/memory is not completely occupied.

CUDA guarantees that *all threads from a single kernel call complete before any threads from a subsequent kernel call are scheduled*.

Within a single kernel call, thread blocks are scheduled to run the kernel code in any order on the GPU SMs (meaning non-deterministic). Thus, a programmer should not assume any ordering of execution between threads in different thread blocks.