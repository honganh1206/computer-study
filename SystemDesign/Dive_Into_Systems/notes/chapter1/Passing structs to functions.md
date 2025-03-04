---
id: Passing structs to functions
aliases:
  - Passing structs to functions
tags: []
---

# Passing structs to functions

In C, arguments of **ALL** types are _[passed by value](../chapter2/Pass by value.md)_ to functions.

That means when we pass a struct argument, the argument's value is passed to the function's parameter, and **the parameter gets a COPY of ours argument's value**

> [!IMPORTANT] > **TLDR**: If a function changes field values of a struct parameter, the corresponding field values of the argument _remain unchanged_
> Changes to the parameter's fields only modify values in the parameter's memory locations for those fields. That is, the argument's memory locations for those fields remain unchanged.

```c
// The base address of the array old will be copied to the parameter old
// The parameter will point to the SAME set of array elements in memory
// And thus change the element's value in the argument
void changeName(char *old, char *new) {
    if ((old == NULL) || (new == NULL)) {
        return;
    }
    strcpy(old,new);
}

int main() {
    // [...]
    // passing a struct field value
    changeName(student2.name, "Kwame");
    printf("student 2's name is now %s\n", student2.name);
    return 0;
}
```
