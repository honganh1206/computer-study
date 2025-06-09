Quite similar to [[Superscalar]], but in this case the **compiler** is responsible for constructing the multiple independent instruction streams executed in parallel

A compiler for a VLIW architecture analyzes the program instructions to statically construct a VLIW instruction that *consists of multiple instructions*, each instruction from each independent stream

VLIW leads to simpler processor design compared to superscalar, since it does NOT need to perform dependency analysis to construct multiple independent instruction streams, but instead *added circuitry* to fetch the next VLIW instruction and break it up into multiple instructions

