Cachegrind helps programmers study how a program or particular function affects the cache.

Cachegrind can *autodetect the cache organization of a machine*. In the cases that it cannot do so, Cachegrind can simulate the 1st level (L1) cache and the last level (LL) cache.

Cachegrind assumes the first level cache has two independent components: The instruction cache and the data cache. This assumption matches the structure of most modern software.

Output information:

- Instruction cache reads (`Ir`)
- L1 instruction cache read misses (`I1mr`) and LL cache instruction read misses (`ILmr`)    
- Data cache reads (`Dr`)
- D1 cache read misses (`D1mr`) and LL cache data misses (`DLmr`)
- Data cache writes (`Dw`)
- D1 cache write misses (`D1mw`) and LL cache data write misses (`DLmw`)

D1 total access is `D1 = D1mr + D1mw` and LL total access is `LL = ILmr + DLmr + DLmw`

Sample output when running `valgrind --tool=cachegrind --cache-sim=yes ./matrix 100`

```css
==746344== Cachegrind, a cache and branch-prediction profiler
==746344== Copyright (C) 2002-2017, and GNU GPL'd, by Nicholas Nethercote et al.
==746344== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==746344== Command: ./matrix 1000
==746344== 
--746344-- warning: L3 cache found, using its data for the LL simulation.
--746344-- warning: specified LL cache: line_size 64  assoc 8  total_size 12,582,912
--746344-- warning: simulated LL cache: line_size 64  assoc 12  total_size 12,582,912
v1 average is: 50.02; time is 0.042543
v2 average is: 50.02; time is 0.054631
==746344== 
==746344== I   refs:      110,491,935
==746344== I1  misses:          1,521
==746344== LLi misses:          1,508
==746344== I1  miss rate:        0.00%
==746344== LLi miss rate:        0.00%
==746344== 
==746344== D   refs:       52,229,636  (44,157,473 rd   + 8,072,163 wr)
==746344== D1  misses:      1,255,677  ( 1,192,033 rd   +    63,644 wr)
==746344== LLd misses:         64,867  (     1,400 rd   +    63,467 wr)
==746344== D1  miss rate:         2.4% (       2.7%     +       0.8%  )
==746344== LLd miss rate:         0.1% (       0.0%     +       0.8%  )
==746344== 
==746344== LL refs:         1,257,198  ( 1,193,554 rd   +    63,644 wr)
==746344== LL misses:          66,375  (     2,908 rd   +    63,467 wr)
==746344== LL miss rate:          0.0% (       0.0%     +       0.8%  )

```

Edit the generated output `cachegrind.out.28657` with `cg_annotate cachegrind.out.28657`