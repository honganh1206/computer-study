```bash
# Run massif tool
valgrind --tool=massif ./matrixVector 10000 10000
# Print the massif.out file
ms_print massif.out.712687
```

Massif is the useful tool to identify areas of high heap memory use in programs, which often slows a program down e.g., memory leaks when programmers call `malloc` without calling `free`