## Dataflow through databases

One process encodes the data, and one process decodes it. There might be several processes accessing the database at the same time.

A value in the database might be written by newer code and read by older code, so forward compatibility is required for databases.

There is also a case when we add a field to a record schema, and the newer code writes a value to that field, but there is older code reads the record then writes it back -> Old code should keep the new field intact.

![[image-4.png]]

*Different values written at different times*: Data outlives code, code constantly changes, while data might stay for many years. Most databases use `null` default value when adding new column to avoid rewriting old data.

*Archival storage*: When dumping data to warehouse, the data will typically encoded using the latest schema. The data dump would mostly be immutable, so Avro and Parquet are good choices for this process.

## Dataflow through Services

### REST

Most common: Clients and servers.

Ajax: A client-side JavaScript application running inside a web browser can use
XMLHttpRequest to become an HTTP client.

A server could be a client to a service, like a client to a database (microservices).

Data encoding used by servers and clients must be **compatible** across versions of the service API.

REST is not a protocol, but a philosophy that builds upon the principles of HTTP, using URLs for identifying resources and HTTP features for cache control, authentication, etc.

SOAP is an XML-based protocol for making API requests which avoids using most HTTP features.

The API of SOAP uses an XML-based language called the Web Service Description (WSDL), which enables code generation so a client can access a remote service using local classes and methods (quite like Protocol Buffers)

SOAP is falling out of favor for its complexity integrating into the ecosystem.

[[Remote Procedure Call (RPC)]]

## Message-Passing Dataflow

Similar to RPC that a client's request is delivered to another process with low latency, and similar to databases that the message is sent NOT via a direct network but via a *message broker*.

Benefits of using a broker:
- Work as a buffer
- Automatically re-deliver messages to a crashed process
- Sender does not need to know the IP
- Can send one message to several recipients
- Decouple sender from recipient (sender just publishes without knowing who will consume)

[[Message Brokers]]

[[Distributed Actor Frameworks]]