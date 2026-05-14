> [!summary]
> - Encodings affect not just efficiency but also the architecture of applications.
> - Rolling upgrades are where a new version of a service is gradually deployed to a few nodes at a time, allowing minimized downtime and less risk (detect faulty releases early).
> - All data flowing around the system must provide backward compatibility (new code can read old data) and forward compatibility (old code can read new data)
> - Programming language-specific encodings are restricted to a single programming language, thus often fail to provide forward + backward compatibility
> - Textual formats like JSON, XML, CSV are widespread, but they are vague about data types.
> - Binary schema-driven formats like Protocol Buffers are efficient and compile-time guratanteed, but data needs to be decoded before it's human-readable.
> - Three dataflows: Databases (processes reading/writing the data), RPC and REST APIs (client encodes, server decodes), and asynchronous message passing (message brokers or actors).

When a data format or schema changes, we need to update the application code by performing *rolling upgrade* to minimize downtime (server side), but for client-side applications it's at the mercy of the users.

We need to maintain both *backward compatibility* (newer code can read data written by older code) and *forward compatibility* (in reverse)

[[Formats for Encoding Data]]

[[Modes of Dataflow]]

