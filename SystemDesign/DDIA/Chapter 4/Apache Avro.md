Another binary encoding format, quite similar to [[Thrift and Protocol Buffers]]

Two schema languages: Avro IDL and JSON

```avro_idl
record Person {
	string userName;
	union { null, long } favoriteNumber = null;
	array<string> interests;
}
```

An integer is encoded using variable-length encoding.

![[image-3.png]]

## The writer's schema and the reader's schema

When the application writes the data, it uses the writer's schema and vice versa.

Avro supports that both schemas *don't have to be the same*. Avro resolves the conflicts by looking at both and translate the data from the writer's schema into the reader's schema.

## Schema evolution rules

To maintain compatibility, you may only add or remove a field that has a default value, because when a reader using the new schema reads the record with the old schema, that field is filled with a default value.

`null` is not acceptable for Avro and we have to use union type like `union { null, long, string }`

## Writer's schema

How does a reader know the writer's schema with which a piece of data is encoded?

Large file with many records: The writer includes the schema at the beginning of the file.

Database with individually written records: Keep a schema version number, and keep a schema in the database with a version.

Sending records over network: Two processes can negotiate the schema and use the agreed schema throughout the lifetime of the connection.

## Dynamically generated schemas

Avro does not contain any tag number because it is friendlier to *dynamically generated schemas*. 

Scenario: Dumping database contents to a file using binary format -> Generate an Avro schema, encode the database contents using that schema, dump it all to Avro object container file.

When the database schema changes, we generate a new Avro schema. The data export process can just do the conversion without knowing about the schema changes (Unlike Protocol Buffers and Thrift with them we have to do manual mapping).

## Code generation and dynamically typed languages

Thrift and Protocol Buffers rely on code generation. After defining a schema, we generate code that implements this schema -> This is good for statically typed languages, but not so much for dynamically typed programming languages since there is no compile-time type checker.

Avro provides optional code generation, but we can just open an object container file using Avro library and look at the data.

