---
id: Head-of-line blocking
aliases:
  - Head-of-line blocking
tags: []
---

# Head-of-line blocking

Queueing delays often account for a large part of the response time at high percentiles aka the slowest requests. As computer systems can only handle a small number of things in parallel, only a small number of slow requests is needed to _stall the processing of subsequent requests_ aka **head-of-line blocking**

Even if subsequent requests are processed fast on the server, the client will still see a slow overall response time due to _the time waiting for the request to complete_. For this reason, it is important to _measure response time on the client side_

```mermaid
graph TD
    A[End-user request] --> B[Web application]
    B --> C[Backend 1]
    B --> D[Backend 2]
    B --> E[Backend 3]
    B --> F[Backend 4]
    B --> G[Backend 5]
    B --> H[Backend 6]
    B --> I[Backend 7]
    C --> J[Response]
    D --> J[Response]
    E --> J[Response]
    F --> J[Response]
    G --> J[Response]
    H --> J[Response]
    I --> J[Response]
    J --> K[End-user]

```
