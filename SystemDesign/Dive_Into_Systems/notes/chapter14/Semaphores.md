The goal of **semaphores** is to *manage concurrent access to a pool of resources*. It is NOT to answer the question *who owns what* but instead *how many resources are still available*.

What makes semaphores different from mutexes:

- Semaphores need NOT be in a binary (locked/unlocked).
- Semaphores can be locked by default.

**Counting semaphore** is a special type of semaphore. It can range in value from 0 to r, where r is *the number of possible resources*. Anytime a resource is produced, the semaphore is incremented, and it is decremented when a resource is used. 

When a counting semaphore has a value of 0, it means that no resources are available, and any threads that want to acquire a resource must wait.

Semaphores also have the advantage that *any thread can unlock the semaphore* (unlike mutexes in which the calling thread must unlock it).