---
id: 3-Conditionals and Loops
aliases:
  - 3-Conditionals and Loops
tags: []
---

# 3-Conditionals and Loops

## Logical operators

C does NOT provide a Boolean type with true or false values. Instead **integer values evaluate to true or false** when ised in conditional statements: `0` evalues to false and non-zero evaluates to true

Logical negation `!`

Logical and `&&`

Logical or `||`

> [!IMPORTANT]
> C' **short-circuit** logical operator evaluation stops evaluating a logical expression _as soon as the result is known_. For example, if the first operand of `&&` evaluates to false, the entire `&&` expression must be false.

## Loops

`while` loop in C is similar to the one in python

```c
while (<boolean expression>) {
  <true body>
}
```

`for` loop in C is a bit different: They are _more general looping constructs_

We evaluate the initialization -> boolean expression -> statements ins inside `<body>` -> `<step>` expression then repeat from step (2)

TLDR: We do not use `in range` in C

```c
for ( <initialization>; <boolean expression>; <step>) {
  <body>
}
```

> [!TIP]
> Just because C supports **a list of statements** for initialization and step parts, it is best to **keep it simple**

In C, `for`and `while` loops are **equivalent in power** so they can be used in place of each other. This is not the case for Python.
