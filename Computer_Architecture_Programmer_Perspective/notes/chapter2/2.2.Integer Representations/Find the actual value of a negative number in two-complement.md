Tags: #review #computer 

In two's-complement representation, the leftmost bit is the **sign bit**, where 1 indicates the *negative number* and 0 indicates a *positive number*.  An example would be `[10111]` and since the bit vector starts with 1, we know this represents a negative number.

How we find the actual value:

1. Flip all bits: `[10111]` becomes `[01000]`
2. Add 1 bit: `[01000] + 1 = [01001]`
3. Read as a normal binary number: $2^{3}+2^{0}=9$
4. Since 1 is the sign but, the value is negative -9
