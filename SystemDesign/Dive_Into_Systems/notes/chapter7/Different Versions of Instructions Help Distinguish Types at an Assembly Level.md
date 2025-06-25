At the Assembly level, there is no notion of types. The compiler instead *uses separate instructions* to distinguish between logical and arithmetic shifts

Recall that: The compiler will use component registers based on types (signed or unsigned) + Shift right works differently depending on whether or not the value is signed or unsigned (More in [[Right Shifting]])