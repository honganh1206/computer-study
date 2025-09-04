The **row-major order** defines that all of row 0's elements comes first, followed by all of row 1's element, and so on.

```css
Address  | Memory  | Element
---------|---------|---------
 1230    | ██████  | [0][0]  
 1234    | ██████  | [0][1]  
 1238    | ██████  | [0][2]  
 1242    | ██████  | [0][3]  <-- Row 0
 1246    | ██████  | [1][0]  
 1250    | ██████  | [1][1]  
 1254    | ██████  | [1][2]  
 1258    | ██████  | [1][3]  <-- Row 1
 1262    | ██████  | [2][0]  
 1266    | ██████  | [2][1]  
 1270    | ██████  | [2][2]  
 1274    | ██████  | [2][3]  <-- Row 2
 ...     | ...     | ...
```

Think of it this way: 

```css
// Your matrix might look like this conceptually
[1  2  3  4 ]
[5  6  7  8 ]
[9  10 11 12]
[13 14 15 16]

// In physical memory, the matrix is stored as one long sequence
[1][2][3][4][5][6][7][8][9][10][11][12][13][14][15][16]
```