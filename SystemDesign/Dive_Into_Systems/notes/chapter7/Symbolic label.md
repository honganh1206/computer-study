An identifier in the program's object file

Labels can be *either local or global* to an object file's scope

Function labels tend to be global. They usually consist of a function name and a colon. An example is `main:` or `<main>:` used to label a user-defined `main function`

Local-scoped labels are preceded by a period like `.L1`

**All labels have an associated address**. When CPU executes `jmp L`, it modifies `%rip` to reflect the program address specified by `L`

We can explicitly specify an address to jump to using `jmp *`

Relative offset: An instruction whose address is 28 bytes away from `main` can be represented as `<main+28>`

`jmp 0x8048427 <main+28>` means jumping to the address `0x8048427` which has the associated label `<main+28>`