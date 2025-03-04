---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#clang"
cssclasses:
  - center-images
---
In C, we can **dereference a pointer with array notation**, and we can *reference array elements with pointer notation* 


```c
void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++) {
    printf(" %.2x", start[i]); // Here we reference array elements with pointer notation
    printf("\n");
  }

  printf("Total byte length: %zu\n", len);
}

```

## Pointer creation and dereferencing

`&` is the **“address of”** operator in C, meaning the expression `&x` **creates a pointer** to the location **holding the object indicated by variable `x`** 

As **the type of the pointer depends on the type of x**, so we can have pointer types like `int *, float *, void **`. The `void *` is a *special kind of pointer* with no associated type information.

The cast `(byte_pointer) &x` indicates that no matter the type the pointer `&x` had before (previously it could be `int/float/double`), *the program will now reference a pointer to the data of type `unsigned char`*. 

Note that the casting **does not change the actual pointer**; it just **instructs** the compiler to **still** refer to the data being pointed at after it has a new data type.


```c
void show_float(float x) {
// Here the memory address is not changed after casting
// The compiler still refers to the data with its new data type
  show_bytes((byte_pointer) &x, sizeof(float));
}

```
