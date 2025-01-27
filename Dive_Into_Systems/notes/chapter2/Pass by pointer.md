---
id: Pass by pointer
aliases:
  - Pass by pointer
tags: []
---

# Pass by pointer

The parameter if the invoked function receives a **value of an address**, and we still cannot change the value passed into the parameter

However, after we dereference a pointer parameter, _the invoked function can change the contents of memory_ that both the parameter and argument refer to.

```c
int change(int *input, int amt) {
  int val;
  val = *input;  // Receive the value that input points to
  *input += amt; // Update the value of input pointer

  return val;
}

int main() {
  int x, result;

  x = 10;

  result = change(&x, 20);

  printf("result = %d. x = %d\n", result, x); // result = 10. x = 30
  // The argument's value reflects the change made to it through the pointer parameter

  return 0;
}
```
