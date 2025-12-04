A packet is born, then is wrapped/encapsulated in a header by the 1st protocol (e.g., TFTP) -> The while thing is encapsulated by the next protocol (UDP) -> Again by IP -> Final protocol on the hardware layer (Ethernet)

When a computer receives the packet, the hardware strips the packet and finally has the data.

[[Layered Network Model]]

## How we encapsulate data

We stick a header on encapsulated data with identifying information or packet length. The header should be the binary data to represent what we need.

Example: When we sends a "Hello" to a chat room, two pieces of information are required: What was said and who said it.

We encapsulate the data in a tiny header and packet structure. Both the client and the server should know how to pack/marshal and unpack/unmarshal.

Packet structure pulled out of thin air:

1. `len` (1 byte, unsigned)—The total length of the packet, counting the 8-byte user name and chat data. Stored in Network Byte Order
2. `name` (8 bytes)—The user’s name, NUL-padded if necessary.
3. `chatdata` (_n_-bytes)—The data itself, no more than 128 bytes. The length of the packet should be calculated as the length of this data plus 8 (the length of the name field, above).

The packet should look like this:

```css
   0A     74 6F 6D 00 00 00 00 00      48 69
(length)  T  o  m    (padding)         H  i

```

It should be safe when we call `send()` or `sendall()` to send the data, but we need to do a bit of extra work when receiving data: *We might receive partial data*, so we need to call `recv()` repeatedly until the packet is completely received. In this scenario, we will prepare only one packet and a buffer large enough for the packet. 

Or we can first call `recv()` and stick the data to the 1st packet, then continue calling `recv()` and stick the rest (make sure to check what's left) to the 2nd packet.

> Make sure to check if the number of bytes in the buffer is equal or greater than the specified length in the header.