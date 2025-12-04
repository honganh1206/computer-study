It's easy to send text data across the network, but for binary data like integers or floats, we need to *encode it into a portable binary form/marshall/serialize*, and *the receiver will decode it*.

An example is `htons()`, which we use to encode a number from whatever the host format is into Network Byte Order. The reverse is `ntohs()`

We use the [RFC 4506](https://tools.ietf.org/html/rfc4506) standard as a good format when packing data.