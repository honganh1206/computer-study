```c
int sumUp2(int n) {
    int total = 0;             //initialize total to 0
    int i;
    for (i = 1; i <= n; i++) { //initialize i to 1, increment by 1 while i<=n
        total += i;            //updates total by i
    }
    return total;
}
```

The Assembly version will be identical to the one of [[While loop in Assembly in x86-64 ISA]]

But why? See the structure of `for` loop

```
for ( <initialization>; <boolean expression>; <step> ){
    <body>
}
```

And of the `while` loop

```
<initialization>
while (<boolean expression>) {
    <body>
    <step>
}
```