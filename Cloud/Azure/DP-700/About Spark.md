An open source parallel processing framework for large-scale data processing and analytics

Spark uses a divide-and-conquer approach to process large volumes of data by **distributing the work across multiple machines**. Spark is also responsible for collating the results

Node - A machine in a Spark cluster that processes data

Executor - A worker process inside a node that runs tasks

Task - A unit of work assigned to an executor

![[Pasted image 20250413161050.png]]

A **head node** in the Spark pool coordinates distributed processes through a driver program 

The pool includes *multiple worker nodes* on which **executor** processes perform the actual data processing

![[image-4.png|Spark pools]]
