Loop fission is when the compiler *splits the single loop into two separate loops*.

```c
// original
for (i = 0; i < rows; i++) {
    fillArrayRandom(matrix[i], cols);
    fillArrayZeros(result[i], cols);
}

// Loop fission
for (i = 0; i < rows; i++) {
    fillArrayRandom(matrix[i], cols);
}

for (i = 0; i < rows; i++) {
    fillArrayZeros(result[i], cols);
}
```

The *opposite* of loop fission is loop fusion: Taking two loops operating over the same range and combining their contents into a single loop.

