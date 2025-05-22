
![[image-18.png]]

We have one data input to *each register circuit* of the register file and two output values `out0` and `out1`

The DMUX takes on input value (Data in) and chooses which of $N$ outputs to send the value to. The not-selected outputs $N-1$ will receive the value 0. The `Sw` selection input will determine which register the DMUX will choose

If the value of WE is 0, *no value will be written to the register*

