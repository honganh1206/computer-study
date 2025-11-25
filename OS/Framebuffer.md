Hardware device used to display a buffer of memory on the screen with 80 columns and 25 rows.

Writing text to the console via the framebuffer is done with memory-mapped I/O. The starting address of the memory-mapped I/O for the framebuffer is `0x000B8000`

The memory is divided into 16 bit cells, and they determine the character, the foreground and background color

```css
Bit:     | 15 14 13 12 11 10 9 8 | 7 6 5 4 | 3 2 1 0 |
Content: | ASCII                 | FG      | BG      |
```

```css
/* Write character A with a green foreground (2) and drak grey background (8) at place 0,0 */
mov [0x000B8000], 0x4128

/* Second cell corresponds to row zero, column one and therefore */*
0x000B8000 + 16 = 0x000B8010
```

How we do it in C:

```c
char *fb = (char *) 0x000B8000
fb[0] = 'A'; // Character
fb[1] = 0x28; // Foreground and background color
```

## The cursor

Moving the cursor of the framebuffer is done via two different I/O ports.

The cursor's position is determined with a 16 bits integer: 0 means row zero, column zero; 1 means row zero, column one; 2 means row one, column 1, etc.

Since the cursor is 16 buts large, and the `out` assembly code instruction argument is 8 bits, *the position must be sent in two turns*, first 8 bits and then the next 8 bits.

Port `0x3d4` is the port that describes the data and port `0x3d5` is the data itself.

```css
/* Set the cursor at row one, column 0 (position 80 = 0x0050) */
out 0x3D4, 14 /* 14 tells the framebuffer to expect the highest 8 bits of the position */
out 0x3D5, 0x00 /* sending the highest 8 bits of 0x0050 */
out 0x3D4, 15 /* 15 tells the framebuffer to expect the lowest 8 bits of the position */
out 0x3D5, 0x50 /* sending the lowest 8 bits of 0x0050 */
```