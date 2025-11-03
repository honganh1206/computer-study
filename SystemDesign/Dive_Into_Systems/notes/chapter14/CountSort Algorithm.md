A simple linear O(N) sorting algorithm to sort a small range of R values where *R is much smaller than N*.

For example with an array as below

```css
A = [9, 0, 2, 7, 9, 0, 1, 4, 2, 2, 4, 5, 0, 9, 1]
```

The algorithm works as follow:

1. Count the frequency of each value in the array
2. Overwrite the original array by enumerating each value by its frequency. 

The `counts` array for the above array should look like:

```css
/*Three zeros, two ones, three twos, etc.*/
counts = [3, 2, 3, 0, 2, 1, 0, 1, 0, 3]
```

The frequency of each value is placed in a `count` array of length 10. The sum of all elements in the `counts` array should be equal to 15.

We then use the `counts` array to overwrite the original `A` array, using the frequency counts to *determine the set of indices in `A` that store each consecutive value in sorted order*. For example, if there are three 0s in the `counts` array, we overwrite the original array with three 0s at the start.

The overwritten array should look like this:

```css
A = [0, 0, 0, 1, 1, 2, 2, 2, 4, 4, 5, 7, 9, 9, 9]
```

The two steps above both benefit from parallelization. We can create multiple threads and assign each thread a chunk of elements to process, but we have to create two sessions of thread-using: One for `countElems` and one for `writeArr`.

> [!important] Determinism
> The output of the program should be correct and consistent *regardless* of the number of threads used.