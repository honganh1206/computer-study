---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#computer"
cssclasses:
  - center-images
---
Sometimes a machine in little-endian mode needs to communicate data to a big-endian mode machine, meaning *the bytes within a word being in reverse order*.

To avoid this, *code written for network applications must follow established conventions* to ensure:

1. The sending machine converts its internal representation to the network standard
2. The receiving machine converts the network standard to its internal representation

(More in Chapter 11)

