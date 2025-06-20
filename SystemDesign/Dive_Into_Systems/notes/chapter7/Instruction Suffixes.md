
Common and arithmetic instructions have a *suffix* that indicates the size (associated with the type) of the data operated at program level

| Suffix | C Type                                | Size (bytes) |
| ------ | ------------------------------------- | ------------ |
| b      | `char`                                | 1            |
| w      | `short`                               | 2            |
| l      | `int` or `unsigned`                   | 4            |
| s      | `float`                               | 4            |
| q      | `long`, `unsigned long`, all pointers | 8            |
| d      | `double`                              | 8            |
|        |                                       |              |

> [[Conditional execution instructions]] have different suffixes based on the evaluated condition