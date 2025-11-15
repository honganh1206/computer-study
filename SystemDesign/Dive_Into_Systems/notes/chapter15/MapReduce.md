Origins of MapReduce lay in functional programming's Map and Reduce operations.

The `map` operation applies the same function to all elements in a collection. The `reduce` operation takes a collection of elements and combines them into a single value.

## The MapReduce programming model

```c
// Word Frequency program to determine the frequency of each word in a large text corpus

void map(char *key, char *value) {
    // key is document name
    // value is string containing some words (separated by spaces)
    int i;
    int numWords = 0; // number of words found: populated by parseWords()

    // returns an array of numWords words
    char *words[] = parseWords(value, &numWords);
    for (i = 0; i < numWords; i++) {
        // output (word, 1) key-value intermediate to file system
        emit(words[i], "1");
    }
}

void reduce(char *key, struct Iterator values) {
    // key is individual word
    // value is of type Iterator (a struct that consists of
    // a items array (type char **), and its associated length (type int))
    int numWords = values.length();  // get length
    char *counts[] = values.items(); // get counts
    int i, total = 0;
    for (i = 0; i < numWords; i++) {
        total += atoi(counts[i]); // sum up all counts
    }
    char *stringTotal = itoa(total); // convert total to a string
    emit(key, stringTotal); // output (word, total) pair to file system
}
```

Visualize it with the song "Code Monkey":

![[image-5.png]]


### Map phase: 

The boss node first partitions the input into `M = 3` parts as 3 Map tasks. During the Map phase, the boss node distributes the Map tasks among one or more worker nodes. Each Map task emits its intermediate values like `(monkey, 1)` to a distributed filesystem.

### Reduce phase

The framework aggregates and combines the intermediate key-value pairs into `(key, list(value))` pairs like `(get, 1)` to `(get, [1, 1])`, and the aggregated intermediate pairs are also written to the distributed filesystem.

The framework then directs the boss node to generate `R = 8` reduce tasks, and each task then executes independently to turn `(get, [1, 1])` to `(get, 2)` by a worker node.

Each worker node appends the output to a final file.