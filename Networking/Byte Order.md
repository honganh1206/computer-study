[[Byte ordering inside the machines]]

[[How we will order the bytes in memory]]

## Little-Endian

We store the bytes in reverse, meaning `b34f` would be stored in memory as `4fb3`.

## Big-Endian

Also called *Network Byte Order* (the more favored one)

Our computers stores numbers in Host Byte Order, and it depends on the architecture e.g., Intel 80x86 would use Little-Endian, while Motorola 68k would use Big-Endian

## Conversion between differing endianness

Two types of numbers for conversion: `short` (two bytes) and `long` (four bytes)

| Function    | Description           |
| ----------- | --------------------- |
| htons()<br> | host to network short |
| htonl()<br> | host to network long  |
| ntohs()<br> | network to host short |
| ntohl()     | network to host long  |
