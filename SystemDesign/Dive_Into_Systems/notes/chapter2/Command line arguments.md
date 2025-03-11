---
id: Command line arguments
aliases:
  - Command line arguments
tags: []
---

# Command line arguments

The `main` function takes all the command line arguments

```c
// 1st parameter is the argument count
// 2nd parameter stores the argument vector
int main(int argc, char *argv[]...) {...}
```

The `argv` array contains `argc + 1` elements. The first `argc` elements store the _command line argument strings_, and the last element stores `NULL` signifying the end of the command line argument list

> [!IMPORTANT]
> The strings in `argv` are **immutable** (they are stored in read-only memory)

C's standard libraries provide functions to convert strings to other types like `atoi` (ASCII to integer)
