Tags: #review #computer #study 

We do multiplication with bit vectors in *the same way we do it with numerical values*: Multiply each bit with each bit of the other vector.

Supposed we have two 3-bit numbers 5 `[101]` and 3 `[011]`

```
101  (5)
× 011  (3)
------
  101  (from 1st 1 in 011)
 101   (from 2nd 1 in 011)
000    (from 0 in 011)
------
01111  (15)
```

