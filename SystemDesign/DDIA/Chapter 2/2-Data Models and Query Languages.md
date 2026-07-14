---
id: 2-Data Models and Query Languages
aliases: []
tags: []
---
> [!summary]
> - Data started out as hierarchical model (one big tree), but it was not good with many-to-many relationship, thus we have the relational model.
> - Non-relational databases were born for when data is a self-contained documents (document databases) or when anything is potentially related to everything (graph databases).
> - Non-relational databases do not enforce a schema for the data they store, but applications still assume whether the stored data has a structure, either enforced on write or handled on read.
# 2-Data Models and Query Languages

Most applications are built by _layering one data model on top of another_. But the question remains: [How is it represented in terms of the next-lower layer?](./How is it represented in terms of the next-lower layer.md)

Each layer hides the complexity of the deeper layers by providing a clear data model. Each layer is for a different group of people

To master just one data model is hard enough already (think of how many books on relational data modeling!). But since the data model has a profound effect on the software, we must choose one appropriate for the application and learn it well

[[Relational Model vs Document Model]]

[[Query Languages for Data]]

[[Graph-like Data Models]]
