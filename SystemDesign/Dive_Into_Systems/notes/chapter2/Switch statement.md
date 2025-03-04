---
id: Switch statement
aliases:
  - Switch statement
tags: []
---

# Switch statement

`switch` statement yields _more concise code branching sequences_. It also allows the compiler to _produce branching code that executes more efficiently_ compared to chaining `if-else` statement

```c
switch (<expression>) {
  case <literal value 1>:
    <statements>;
    break;
 // breaks out of switch statement body
  case <literal value 2>:
    <statements>;
    break;
 // breaks out of switch statement body
...
  default:
 // default label is optional
    <statements>;
}
```

Execution:

1. `<expression>` evaluates first
2. `switch` searches for a `case` literal value that _matches the value of the expression_
3. Execute the `<statements>` after finding the matching case
4. If no matching case is found, execute the `default` if present. Otherwise, execute nothing

> [!IMPORTANT]
>
> - The value associated with `case` must be a **literal value** and CANNOT be an expression
> - Reaching a `break` statement stops the execution of ALL remaining statements inside the body of `switch`
> - Without a `break` statement at the end of a `case`, the statements under the subsequenct cases will be executed until there is a `break` statement
