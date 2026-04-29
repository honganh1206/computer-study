# Many-to-One and Many-to-many Relationships

For data like regions and industries (many-to-one), we should standardized lists of geographic regions and industries as list of IDs, instead of storing them in plain text for consistency, avoiding ambiguity, search optimization, etc.

Whether you store an ID or a text string is a question of duplication. An ID has no meaning to human and can remain the same, while text (meaningful to human) may need to change sometime.

If text information is duplicated, all the redundant copies need to be updated, which risks inconsistencies. We thus need to do *normalization* (removing duplication) in databases.

## Are document databases repeating history?

The design of IMS (Information Management System created by IBM) is remarkably similar to the JSON model: It represents all data as *a tree of records nested within records*.

At that time, IMS did not support many-to-many relationships and joins as well. Thus, developers had to decide whether to duplicate (denormalize) data or to manually resolve references from one record to another.

### The network model

The Conference on Data Systems Language (CODASYL) model was a *generalization* of the hierarchical model.

**A record could have multiple parents**. Example: One record for "Hanoi" region, and every user who lived in that region could be linked to it.

The links between records were similar to pointers in a programming language.

A query in CODASYL was performed by *moving a cursor through the database by iterating over lists of records and following access paths.* However, if a record has multiple parents, the application code has to *keep track of all the various relationships*.

### The relational model

A relation (table) is simply *a collection of tuples (rows)*.

In a relational database, the query optimizer *automatically* decides which parts of the query to execute in which order, and which indexes to use.

Either build a query optimizer once, or hardcode the access paths for a particular query, but the former wins in the long run.

Compare to document databases: Share the aspect "storing nested records", foreign key == document reference.
