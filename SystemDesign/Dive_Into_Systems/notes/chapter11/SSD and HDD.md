A hard disk of an HDD consists of a few flat, circular platters made from a material that *allows magnetic recording*. The platters can rotate up to 5,000 to 15,000 revolutions per minute. AS the platters spin, a small mechanical arm with a disk head at the tip moves across the platter to read/write data on *concentric tracks* i.e., regions of the platter located at the same diameter.

![[01-Areas/Computer/SystemDesign/Dive_Into_Systems/notes/chapter11/image-3.png]]

Moving the arm is named **seeking**, and seeking introduces a small *seek time delay* to access data (~ a few milliseconds). And we have to wait for the platter to rotate to the correct position for the arm to points to, thus introducing **rotational latency**. 

SSDs introduce lower latency, since they have *no moving parts* and the [flash memory](https://en.wikipedia.org/wiki/Flash_memory) reigns supreme in commercial SSD devices