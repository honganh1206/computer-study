Protocol Buffers and Thrift are binary encoding libraries that require a schema for any data that is encoded

```thrift
struct Person {
	1: required string userName,
	2: optional i64 favoriteNumber,
	3: optional list<string> interests
}
```

```protocol_buffers
message Person {
	required string user_name = 1;
	optional int64 favorite_number = 2;
	repeated string interests = 3;
}
```

Thrift has two binary encoding formats: BinaryProtocol and CompactProtocol

![[image.png]]

![[image-1.png]]

Protocol Buffers only has one binary encoding format, quite similar to Thrift

![[image-2.png]]

## Field tags and schema evolution

When we add new fields, we give them tag numbers. Old code can ignore those fields if they don't realize the tag numbers.

But we cannot mark a new field required due to backward compatibility. Also we can only remove optional fields.

## Datatypes and schema evolution

When we change the datatype, saying 32-bit integer to 64-bit integer, the new code will just pad the missing bits with zeros, but the old code will truncate the value.

The Protocol Buffers has a `repeated` marker for fields, saying that the same field tag will appear multiple time in the record. New code will read the old data padded with zeros, while old code will read new data as the last element on the list.