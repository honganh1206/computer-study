# Command Query Responsibility Segregation (CQRS)
Split the responsibility of commands (saves - the CUD in CRUD) and queries (reads - the R in CRUD) into **different models**
![[Pasted image 20230817104054.png]]

## Why?
- CQRS allows us to break free from constant  "winning out" act between reads and writes and gives each system the equal design and consideration
- Improve performance and agility especially separate teams are working on these systems

| Advantages                                                                         | Disadvantages                                             |
| ---------------------------------------------------------------------------------- | --------------------------------------------------------- |
| - Single Responsibility </br> - Decoupling </br> - Scalability </br> - Testability | - Complexity </br> - Learning curve </br> - Hard to debug |

---
# Mediator pattern

Define a mediator object that **encapsulates** how objects interact with each other, instead of having objects directly communicating with each other.

![[Pasted image 20230817154937.png]]

- Explanation: `SomeService` sends a message to the Mediator, then the Mediator invokes multiple other services to handle the message => No direct dependency between any services, thus enabling **"loose coupling"**
 