---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---

Recent Intel and AMD processors have instructions e.g., Intel’s instruction set AVX that can add **8 pairs of single-precision floating-point numbers in parallel**.


```c
#include <immintrin.h> // AVX

void add_float_arrays(float* a, float* b, float* result) {
    // Load 8 floats from each array into 256-bit AVX registers
    __m256 vec_a = _mm256_loadu_ps(a);  // Load 8 floats from array a
    __m256 vec_b = _mm256_loadu_ps(b);  // Load 8 floats from array b

    // Perform element-wise addition
    __m256 vec_result = _mm256_add_ps(vec_a, vec_b);

    // Store the result back to the result array
    _mm256_storeu_ps(result, vec_result);  // Store 8 results back to result array
}

int main() {
    float a[8] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f};
    float b[8] = {9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f};
    float result[8];

    add_float_arrays(a, b, result);

    // Print result
    for (int i = 0; i < 8; i++) {
        printf("%f\n", result[i]);
    }

    return 0;
}

```