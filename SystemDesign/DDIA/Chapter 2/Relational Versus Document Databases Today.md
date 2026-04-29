# Relational Versus Document Databases Today


Relational model provides: 

| Document data model                                                                                                                                            | Relational data model                                                      |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------- |
| Schema flexibility, better performance, with locality(?), closer to data structures used by applications.                                                      | Better support for joins + many-to-one and many-to-many relationships.<br> |
| Documents not too deeply nested.                                                                                                                               |                                                                            |
| Data in a document-like structure (a tree of one-to-many relationships and we load the whole tree)                                                             |                                                                            |
| Limitations: Cannot refer directly to a nested item inside a document, we must say: "the second item in the list of positions for user 251”                    |                                                                            |
| Many-to-many relationships do not work well with document data model, and the application code needs to do a lot of normalization to keep the data consistent. |                                                                            |
|                                                                                                                                                                |                                                                            |
## Schema flexibility in the document model

Document databases are NOT schema-less, since the data usually assumes an implicit schema, but the databases do not enforce it.

Document databases should be *schema-on-read* (similar to runtime type-checking), while relational databases are *schema-on-write* (similar to compile-time type-checking.

## Data locality for queries

A document is usually stored as a single string, which has storage locality (we can fetch it once). If data is split across multiple tables, we need multiple index lookups, which increases disk seeks.

However, it can be wasteful to load the entire document just to use a small part of it. Thus, we should keep documents small.

Document and relational databases are becoming more similar over time, with some examples of relational databases supporting both XML type and JSON type/document databases support joins.