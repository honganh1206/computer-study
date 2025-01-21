---
id: Lists of placeholders and modifiers in C
aliases:
  - Lists of placeholders and modifiers in C
tags: []
---

# Lists of placeholders and modifiers in C

Common placeholders

| Placeholder | Type          | Description                                          | Example                                 |
| ----------- | ------------- | ---------------------------------------------------- | --------------------------------------- |
| %d          | int           | Signed decimal integer                               | `printf("%d", 42)` → `42`               |
| %u          | unsigned int  | Unsigned decimal integer                             | `printf("%u", 42)` → `42`               |
| %f          | float, double | Decimal floating point                               | `printf("%f", 3.14)` → `3.140000`       |
| %e, %E      | float, double | Scientific notation                                  | `printf("%e", 3.14)` → `3.140000e+00`   |
| %g, %G      | float, double | Shorter of %e or %f                                  | `printf("%g", 3.14)` → `3.14`           |
| %x, %X      | unsigned int  | Hexadecimal integer (x:lowercase, X:uppercase)       | `printf("%x", 255)` → `ff`              |
| %o          | unsigned int  | Octal integer                                        | `printf("%o", 8)` → `10`                |
| %s          | char\*        | String of characters                                 | `printf("%s", "hello")` → `hello`       |
| %c          | char          | Single character                                     | `printf("%c", 'A')` → `A`               |
| %p          | void\*        | Pointer address                                      | `printf("%p", &var)` → `0x7fff5fbff83c` |
| %n          | int\*         | Nothing printed; stores number of characters written | `printf("hello%n", &var)` → `var = 5`   |
| %%          | -             | Prints a literal % character                         | `printf("%%")` → `%`                    |

Common modifiers:

| Modifier     | Description                      | Example                           |
| ------------ | -------------------------------- | --------------------------------- |
| Width        | Minimum field width              | `printf("%5d", 42)` → `   42`     |
| Precision    | Decimal places                   | `printf("%.2f", 3.1415)` → `3.14` |
| Left-justify | Left-align within field width    | `printf("%-5d", 42)` → `42   `    |
| Zero-padding | Pad with zeros instead of spaces | `printf("%05d", 42)` → `00042`    |
| Plus sign    | Show + for positive numbers      | `printf("%+d", 42)` → `+42`       |
| Space        | Space before positive numbers    | `printf("% d", 42)` → ` 42`       |
