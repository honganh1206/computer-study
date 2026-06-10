A secondary index is a way of *searching for occurrences of a particular value* e.g., find all actions of user 123.

## Partitioning secondary indexes by document

Scenario: Selling used cars. Each listing has a unique Document ID. We partition the database by the IDs.

Supposed we have a secondary index for the color red. Whenever a red car is added to the database, the database partition automatically adds it to the list of document IDs for the index entry color red.

![[image-2.png]]

In this indexing approach, *each partition is completely separate*. When performing CRUD on a partition, we only have to deal with the one containing the document ID we have.

A local index = a document-partitioned index.

Reading from a document-partitioned index requires care, since not all records sharing the secondary index end up in the same partition. *We have to combine the results*.

Although it is suggested that we structure the partition scheme so secondary index queries can be served from a single partition, that is not always possible, and we might have to use multiple secondary indexes in a single query.

## Partition secondary indexes by term

![[image-3.png]]

From the example: Colors from a to r appear in partition 0, but colors from s to z appear in partition 1

We can have a global index that *covers data from all partitions*, but it must also be partitioned to avoid bottleneck.

The name **term** comes from full-text indexes, where the terms are *all* the words that occur in the document.

We can either partition by the term it self (utilizing range scanning) or by a hash of the term (more even distribution of load).

Global indexes make reading more efficient, but now writes are more challenging since a write affect multiple partitions.

Updates to global secondary indexes are often asynchronous (changes take a while to be reflected in the indexes)