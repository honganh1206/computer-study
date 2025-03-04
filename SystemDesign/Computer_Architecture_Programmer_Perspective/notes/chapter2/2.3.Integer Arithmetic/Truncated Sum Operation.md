Tags: #review #computer 

The **truncated sum operation** $+_{w}^u$  for arguments $x$ and $y$ involves adding two integers $x$ and $y$, and the result will be truncated to $w$ bits by *discarding the higher-order bit* and interpreted as an unsigned integer. The result unsigned integer can be computed with the sum modulo $2^w$.

-> Example: Supposed we have two arguments $x=9$ and $y=12$ having bit representation of `[1001]` and `[1100]` respectively. The sum of them would be 21 with the bit representation of `[10101]` (5-bit). 

How does this happen? Here is how we add up the bits

```
1001  (9)
+ 1100  (12)
-------
 10101  (21)
```

1. First bit (right most): 1 + 0 = 1
2. Second bit: 0 + 0 = 0
3. Third bit: 0 + 1 = 0
4. Fourth bit (left most of original numbers): 1 + 1 = 10 (carry the 1)
5. The carried 1 will be the higher-order bit

But what does "carry the 1" mean?

It means we "carry" the 1 to the *next column* to be added with those digits, just like when we add big numbers in decimal. 

When we truncate the high-order bit, we get `[0101]` with the decimal value of 5. This is true for $21\text{mod}16=5$

