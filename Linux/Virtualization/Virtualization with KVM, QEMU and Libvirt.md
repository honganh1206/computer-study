Three architectural pillars of modern Linux virtualization: **KVM (engine), QEMU (body), and libvirt (manager)** that transform physical hardware into efficient cloud infrastructure. 

![[image.png]]

Critical technical concepts such as **Type 1 hypervisors**, the performance impact of **VM exits**, and the necessity of **virtio drivers** to mitigate I/O bottlenecks.

KVM provides direct access to hardware using the existing kernel and drivers

![[image-1.png]]


Understand how to manage **resource contention (noisy neighbor)** and security risks like **VM breakout** through mandatory access control systems.

Resource contention is when shared hallways are used by high-running processes. Bottleneck is waiting for data.


![[image-2.png]]

KVM is a Linux kernel feature

![[image-3.png]]

KVM is a high-privilege kernel communication channel, passing commands and params directly to drivers

![[image-4.png]]

Each vCPU works as a special thread

When KVM_RUN, control leaves user space

We run the KVM_RUN indefintelly
![[image-5.png]]

VM exits are expensive. Every state must be saved securely. Switching privilege rings from guest mode to host mode -> Run guest mode as long as possible

![[image-6.png]]

When we send packets, each packet equals to 1 interrupt (expensive). VirtIO communicates with the host via shared memory queue

![[image-7.png]]


QEMU is a usuer-space application that bridges virtual world with physical host environment

![[image-8.png]]


CPU instructions go through high-speed part, IO handling of guest OS with the real world goes through the slow part, and when that happens, control goes to QEMU

![[image-9.png]]

![[image-10.png]]


What to do when we want to extend? How to share cache?
![[image-11.png]]

We rarely run raw QEMU commands on prod. Think of Libvirt like an ultimate remote controller

![[image-12.png]]

![[image-13.png]]

QEMU process can only interact with resources with the same label

![[image-14.png]]

![[image-15.png]]

Expensive context switching when VM touching a disk or network card is still a bottleneck

![[image-16.png]]