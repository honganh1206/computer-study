Byte alignment refers to *placing code or data at memory address that specify specific boundaries*.

An object is N-byte aligned if its starting address is divisible by N.

Why do we need byte alignment? CPU instructions assume aligned operands for smooth operation, loader must respect boundaries when copying segments into memory?...