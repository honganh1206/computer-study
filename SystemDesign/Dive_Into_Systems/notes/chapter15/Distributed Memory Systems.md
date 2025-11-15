As of now, we have massive tasks that require more physical memory and processors than ever. Thus, we design systems built from multiple computers, each with their own CPU(s) and memory, and they all communicate over a network - we call them a **distributed memory system**

A **supercomputer** is a high-performance system in which many nodes are tightly coupled to *a fast interconnection network*. While each compute node contains its own CPU(s), GPU(s) and memory, but nodes can share resources like secondary storage and power supplies.

A **distributed application** might run on a loosely coupled collection of fully autonomous computers (nodes) connected by a LAN. Such a collection of nodes is known as **commodity off-the-shelf** (COTS) cluster. Those clusters employ a *shared-nothing architecture*, meaning each has its own set of hardware.

![[image-3.png|A shared-nothing architecture built from two compute nodes]]

[[Parallel and Distributed Processing Models]]

[[Communication Protocols]]

## Challenges

Coordinating the behavior of multiple processes is challenging: Autonomous nodes can fail independently, the interconnection network could fail, lacking shared hardware like clocks to determine the order of messages being sent.