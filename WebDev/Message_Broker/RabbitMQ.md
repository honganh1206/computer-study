- Accept & Forward messages
- Producer/Consumer model (Pub/Sub)
- Messages are stored in queues (message buffer)
- Can use persistent storage
- Exchanges can be used for routing functionality
- Use the Advanced Message Queuing Protocol

## Exchanges

### Direct 

- Can only be routed to a single queue

![[Pasted image 20240430104159.png]]

### Fanout

- Exchange can have one or more consumer queues
- Many consumers consume from one or more consumer queues

![[Pasted image 20240430104309.png]]


![[Pasted image 20240430141557.png]]


## Outbox

- Store event data in a database when RabbitMQ is down => Fire the stored event data when the service is back