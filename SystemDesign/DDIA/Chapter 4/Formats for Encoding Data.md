Usually data in memory is kept in objects, structs, etc. but when we want to write data to send over the network, we need to write it to a kind of *self-contained sequence of bytes* like JSON.

The translation from in-memory to byte sequence is called encoding/serialization/marshalling, and the other way is decoding/parsing/deserialization/unmarshalling

## Language-Specific Formats

Programming come with built-in support for encoding in-memory objects into byte sequences e.g., Java has `java.io.Serializable`.

There are reasons why we should not use our language-of-choice's built in encoding: Encoding tied to languages, security problems when decoding, versioning + efficiency as an afterthought.

## JSON, XML and Binary Variants

JSON, XML and CSV are textual formats and they have some problems with encoding numbers and dealing with large numbers, no support for binary strings (sequences of bytes without a character encoding), etc.

[[Binary encoding]]

[[Thrift and Protocol Buffers]]

[[Apache Avro]]

## Merits of schemas

Binary encodings based on schemas are getting more common:
- More compact compared to JSON/XML/CSV
- Make schema more up-to-date
- Backward + forward compatibility
- Ability to generate code with compile-time type checking



