General-purpose registers located in the CPU is *at the top of the memory hierarchy*, and there is only *a small number of them* (between 8-32 depending on the architecture)

The set of [[Registers]] is organized into a *register file circuit*. A register file consists of a set of register circuits (More in [[CPU Register]]) to store values and some [[Control Circuits]] to control reads and writes to its registers

A register file circuit has *one data input line* to write into one of its registers and *two data output lines* to simultaneously read two values from its registers

 ```assembly
ADD R1, R2, R3 # Write destination and the two read sources
```

[[How the register file works]]

