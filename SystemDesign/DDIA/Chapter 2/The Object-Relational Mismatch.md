---
id: The Object-Relational Mismatch
aliases:
  - The Object-Relational Mismatch
tags: []
---

# The Object-Relational Mismatch

Since most of today's software is done in OOP languages, there is some criticism named **impedance mismatch**: An _awkward translation layer_ between the objects in the code and the database model of tables, rows and column

ORM frameworks like Entity Framework or Hibernate reduces the boilerplate code for the transition layer but they cannot hide the differences? between the two models.

JSON representation (NoSQL approach) has better locality compared to multi-table schema, since all the relevant information is in one place (JSON file).