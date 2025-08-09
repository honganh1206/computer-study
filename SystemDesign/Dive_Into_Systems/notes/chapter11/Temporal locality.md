Programs tend to access the same data repeatedly over time 

 ```c
// The repetitive nature of the for loop
// introduces temporal locality for i, len, sum and array (the base address)
int sum_array(int *array, int len) {
    int i;
    int sum = 0;

    for (i = 0; i < len; i++) {
        sum += array[i];
    }

    return sum;
}
```

Exploiting temporal locality allows a system to *load each variable from main memory into the CPU cache only once*.
