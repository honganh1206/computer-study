Tags: #review #computer #study 

We do multiplication with bit vectors in *the same way we do it with numerical values*: Multiply each bit with each bit of the other vector.

But first, here are some rules:

![[Rules For Binary Addition.png]]

## Unsigned

**The easy way**: We do the normal multiplication resulting in a 5-bit number, and for the leftmost bit we need to convert from base 10 to base 2 to see if we need 1 or 0

**The hard way**: In some cases we have to "carry the 1" to the next bit

```
	111
x   101
--------
	111
   000
  111
--------
 111011 (Represented as a 6-bit number)
   (1) -- Carry the 1 from 1 + 1 here
```

Note that with unsigned numbers, we still need to convert the result from decimal form (base 10) to binary form to ensure the binary representation is correct.

## Two's-complement/Signed

**The easy way**: Same as we do with unsigned multiplication but check if the result is negative (1 for MSB) or non-negative (0 for MSB)

 **The hard way**: 

1. **Sign extend** both integers to *twice as many bits*
2. Take the correct number of result bits from the *least significant portion* of the result

An example with 4-bit integers

```
     1111 1111        -1
	   x 1111 1001     x  -7
      ----------------    ------
	      11111111         7
	     00000000
	    00000000
           11111111
          11111111
         11111111
        11111111
   +   11111111
       ----------------
        1  00000000111
              --------  (correct answer underlined)
```

 For two's-complement, note that the MSB should be 0 for non-negative numbers and 1 for negative numbers.
 
More info [here](https://pages.cs.wisc.edu/%7Emarkhill/cs354/Fall2008/beyond354/int.mult.html) 
