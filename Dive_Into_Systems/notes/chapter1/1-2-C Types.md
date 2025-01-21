---
id: 1-2-C Types
aliases:
  - 1-2-C Types
tags: []
---

# 1-2-C Types

C only supports a small set of built-in data types, and from that C programmers can build complex data structures

While the C `char` type stores a numeric value, C programmers use it to _store the value of an ASCII character literal_

```c
8 // int value
3.4 // double value
'h' // char value (its value is 104, the ASCII value of h)

```

C does NOT support a string type, but programmers can _create strings from `char` type_ and C's support for **constructing arrays of values**

In C, a string and a `char` are **two very different types** and they evaluate differently

```c
'h' // char literal value (its value is 104, the ASCII value of h)
"h" // string literal value (its value is NOT 104, it is NOT a char)
```

## C numeric types

| Type name   | Usual size   | Values stored       | How to declare |
| ----------- | ------------ | ------------------- | -------------- |
| `char`      | 1 byte       | integers            | `char x;`      |
| `short`     | 2 bytes      | signed integers     | `short x;`     |
| `int`       | 4 bytes      | signed integers     | `int x;`       |
| `long`      | 4 or 8 bytes | signed integers     | `long x;`      |
| `long long` | 8 bytes      | signed integers     | `long long x;` |
| `float`     | 4 bytes      | signed real numbers | `float x;`     |
| `double`    | 8 bytes      | signed real numbers | `double x;`    |

C's numeric types differ in the **range and precision of the values they represent**: Some types with more bytes can represent a larger value or higher-precision values

C also supports `unsigned` versions of the integer numeric types

```c
int x; // signed int variable
unsigned int y; //.unsigned int variable
```

> [!CAUTION]
> C standard does not specify whether the `char` type is signed or unsigned, so we need to explicitly declare `unsigned char` if we intend to use it as `unsigned`. more in [data type `char` as an exception](01-Areas/Computer/Computer_Architecture_Programmer_Perspective/notes/chapter2/2.1.Information%20Storage/Data%20type%20%60char%60%20as%20an%20exception.md)

We can use the `sizeof` operator to print the **exact size** of a type

## Arithmetic Operators

THe resulting type of the operation is based on the **types of the operands**. For example, if two `int` values are combined with an arithmetic operator, the resulting type is also an `int`

C supports **automatic type conversion**: If an `int` operand is combined with a `float` operand, the integer operand is converted to its `float` equivalent and the resulting type would be of `float` type

```c
1 + 2.00 // Result is 3.00
```

> [!WARNING] Pre- versus Post-increment
> The operators `++variable` and `variable++` behave differently: The former one increments `variable` first then use its value, while the latter one use the value first then increment it.

> [!TIP]
> Write separate statements for the order you want. Instead of `y= ++x + 1;` we can wrte it into two separate statements `x++; y = x + 1;`
