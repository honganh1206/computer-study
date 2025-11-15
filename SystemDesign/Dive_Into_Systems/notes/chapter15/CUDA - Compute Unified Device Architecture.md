CUDA is NVIDIA's *programming interface* for GPGPU computing on is graphics devices.

CUDA is designed for *heterogeneous computing*: Some program functions run on the host CPU, and others run on the GPU device.

Programmers often write CUDA programs in C/C++ with annotations specifying CUDA kernel functions, and those functions call to CUDA library functions to manage GPU device memory.

A **CUDA kernel function** is a function that is executed on the GPU. 

[[CUDA thread]]

## Examples of CUDA programs

 ```c
#include <stdio.h>
#include <cuda_runtime.h>

#define N 512

// Example of Matrix Multiplication using CUDA in C

// Global annotation distinguishes kernel functions from host functions
__global__ void matMul(const float *A, const float *B, float *C, int n) {
	// Uniquely identify thread by its thread position and containing block
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    float sum = 0.0f;

    if (row < n && col < n) {
        for (int k = 0; k < n; k++)
            sum += A[row * n + k] * B[k * n + col];
        C[row * n + col] = sum;
    }
}

int main() {
    size_t bytes = N * N * sizeof(float);

    float *h_A = (float*)malloc(bytes);
    float *h_B = (float*)malloc(bytes);
    float *h_C = (float*)malloc(bytes);

    for (int i = 0; i < N * N; i++) {
        h_A[i] = 1.0f; h_B[i] = 2.0f;
    }

    float *d_A, *d_B, *d_C;
	// Since the memory space of a CUDA program is separated into host and GPU memory,
	// the program must explicitly allocate and free GPU memory
	// to store program data manipulated by CUDA kernels.
    cudaMalloc(&d_A, bytes);
    cudaMalloc(&d_B, bytes);
    cudaMalloc(&d_C, bytes);

    cudaMemcpy(d_A, h_A, bytes, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, bytes, cudaMemcpyHostToDevice);

	// Define 2D block and grid dimensions
    dim3 threads(16, 16);
    dim3 blocks((N + 15) / 16, (N + 15) / 16);
    matMul<<<blocks, threads>>>(d_A, d_B, d_C, N);

	// CUDA programmers must either explicitly copy data to and from the host and GPU memory
	// or use CUDA unified memory, which presents a view of memory space shared by GPU and host.
    cudaMemcpy(h_C, d_C, bytes, cudaMemcpyDeviceToHost);

    printf("C[0] = %f\n", h_C[0]);

    cudaFree(d_A); cudaFree(d_B); cudaFree(d_C);
    free(h_A); free(h_B); free(h_C);
    return 0;
}

```

Consider this CUDA program:

```c
x = a * x    // where x is a vector and a is a scalar value
```

