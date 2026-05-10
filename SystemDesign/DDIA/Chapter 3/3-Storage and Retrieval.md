> [!summary]
> - Storage engines fall into two categories: Optimized for transaction processing (OLTP - for user-facing work) and optimized for analytics (OLAP - for business analysts).
> - On OLTP side, we have the log-structured school (permit appending files and deleting obsolete files) and update-in-place school (disk as a set of fixed-sized pages that can be overwritten)
> - Column-oriented storage helps us encode data compactly when we have to query over many columns for analytic work.

Two families of storage engines: *Log-structured* and *page-oriented* such as B-tree

> [!info]
> Log usually refers to application logs and also an append-only sequence of records. It might be binary for other programs to read.

[[Data structures that power your data]]

[[Transaction Processing or Analytics]]