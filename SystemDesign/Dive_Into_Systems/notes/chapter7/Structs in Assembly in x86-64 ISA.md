Recall [[C Structs]]

C stores a `struct` in a *single-dimension array*, where the fields are stored *contiguously*

![[image-32.png|Memory layout of struct studentT]]

As `name` is the first field of struct `studentT`, the address of the array `student` is synonymous with the address of `student->name`

However, note that the `age` field does NOT immediately follow the `name` field, and the `name` field is modified to be 63 bytes instead of 64

![[image-33.png]]

(Recall [[How structs work with the compiler]])

Why does this happen? We have the [[x64 alignment policy]] which specifies the compiler to add empty bytes as *padding* between fields. This ensures each field satisfies its alignment requirements
