Like calling a function in a programming language, but flawed:
- Calling a function via network request is unpredictable, with machines possible being slow and network problems
- Remote function call may return without a result because of a timeout
- Retrying will cause the action to be performed multiple times without an idempotency mechanism
- Latency is wildly variable
- With local functions, we can pass a pointer to objects in local memory, but with remote functions, we might have to pass large objects.
## Current directions of RPC

gRPC support streams, where a call consists of a series of requests and responses over time.

While RPC protocols with a binary encoding format may achieve better performance than JSON over REST, RESTful API still has advantages like supports for debugging, vast ecosystem, etc.

## Evolution of RPC

Servers will be updated first, and all clients second. Thus, we need backward compatibility on requests, and forward compatibility on responses.

As RPC is often used for communication across organizational boundaries, the service provider has no control over its clients, and often end up with maintaining multiple versions of service API.

