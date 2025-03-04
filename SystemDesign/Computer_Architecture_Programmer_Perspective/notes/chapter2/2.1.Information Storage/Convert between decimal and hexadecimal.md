---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
To convert a decimal number $x$ to hexadecimal, we can **repeatedly divide $x$ by 16**, giving the quotient $q$ and remainder $r$ such that $x = q * 16 + r$

We then use the hexadecimal digit representing $r$ as the *least significant digit* and generate the remaining digits by *repeating the process on $q$*

$$
314,156 = 19,634 * 16 + 12 (C)
$$
$$
19,634 = 1,227 * 16 + 2 (2)
$$
$$
1,227 = 76 * 16 + 11 (B)
$$
$$
76 = 4 * 16 + 12 (C)
$$
$$
4 = 0 * 16 + 4 (4)
$$

Reading from the bottom up, we have $314,156$ represented in hexadecimal as `0x4CB2C`

To convert a hexadecimal number into decimal, we can *multiplate each of the hexadecimal digits by the appropriate power of 16*. To convert `0x7AF`

$$
 7 * 16^2 + 10 * 16 + 15 = 7 * 256 + 10 * 16 + 15 = 1,792 + 160 + 15 = 1,967
$$


> [!info] 
> A single byte ca be represented by 2 hexadecimal digits. The byte `11001010` in binary is represented as `CA` in hexadecimal.


> [!tip] 
> For converting large values between decimal and hexadecimal, it is better to let computers do it.


