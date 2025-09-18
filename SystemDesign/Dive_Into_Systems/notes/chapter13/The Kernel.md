> When we use the term OS alone, we mean the OS kernel.

The kernel implements core OS functionality to:
- Manage the computer hardware layer
- Implement and manage OS abstractions exported to users e.g., files as an abstraction for stored data
- Implement interface to the user applications layer to hardware device layer

The kernel implements **mechanisms** - the "how" part of OS functionality - to implement abstractions such as processes.

The kernel also implements **policies** - the "what", "when" and "to whom" parts - to manage hardware and its abstractions.

The kernel implements the **[[System call]] interface** - a programming interface for users of the system. 

The kernel provides the **device interface** for interacting with hardware devices such as SSDs, HDDs, keyboards, etc. Such devices come with special device driver software that runs in the OS and handles transferring data from/to a specific device.

Like how? The device driver software interacts with the OS via the *device interface* by loading the device driver code into the OS.

![[image.png|Core OS functionality to use the system and facilitate cooperation between I/O devices and users]]

