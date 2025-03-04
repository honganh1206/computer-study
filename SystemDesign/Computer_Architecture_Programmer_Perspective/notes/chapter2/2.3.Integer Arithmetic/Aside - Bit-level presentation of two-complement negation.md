Tags: #review #study #computer 

We have several ways to *determine the two's-complement negation of a value represented at the bit level* for an integer value of $x$

#1: Complement (flip) the bits then increment the result $-x = (\sim{x})\text{++} + 1$ (We use the tilde $\sim$ operator here to denote flipping the bits and $\text{++}$ to denote incrementing )

| $\vec{x}$ |     | $\sim\vec{{x}}$ |     | $(\sim{\vec{x}})\text{++}$ |     |
| --------- | --- | --------------- | --- | -------------------------- | --- |
| `[0101]`  | 5   | `[1010]`        | -6  | `[1011]`                   | -5  |
| `[0111]`  | 7   | `[1000]`        | -8  | `[1001]`                   | -7  |
| `[0000]`  | 0   | `[1111]`        | -1  | `[0000]`                   | 0   |


#2: Split the bit vector into two parts

Let $k$ be the position of the rightmost 1 (the first 1 you encounter) so the bit representation of $x$ has the form $[x_{w-1}, x_{w-2}, \dots, x_{k+1}, 1, 0, ..0]$ (This is possible as long as $x \neq 0$). We then complement each bit on the **left** side of the bit in position $k$ so that it becomes $[-x_{w-1}, -x_{w-2}, \dots, -x_{k+1}, 1, 0,\dots, 0]$

| $\vec{x}$ |     | $-\vec{{x}}$ |     |
| --------- | --- | ------------ | --- |
| `[1100]`  | -4  | `[0100]`     | 4   |
| `[1000]`  | -8  | `[1000]`     | -8  |
| `[0101]`  | 5   | `[1101]`     | -5  |
