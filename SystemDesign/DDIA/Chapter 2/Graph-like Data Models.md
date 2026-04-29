When connections within your data become more complex (more complex than many-to-many relationships), we go for modeling our data as graphs.

A graph consists of vertices (nodes or entities) and edges (relationships or arcs). Think of it like road networks: Vertices are junctions and edges are the roads.

We use graphs to *store different types of objects in a single datastore*. Example: Facebook users as vertices and edges indicating which people are friends with each other.

Cypher is a query language for graph databases, similar to SQL for relational databases.

```cypher
// Seed vertices and edges
CREATE
	(na:Location {name:'North America', type:'continent'}),
	(usa:Location
	 {name:'United States', type:'country' }),
	(id:Location
	 {name:'Idaho',
	 type:'state'
	 }),
	(lucy:Person
	 {name:'Lucy' }),
	(usa) -[:WITHIN]-> (USA) -[:WITHIN]-> (na),
	(lucy) -[:BORN_IN]-> (id)

// Find vertex/person that has an outgoing BORN_IN edge to some vertex
// WITHIN is magical: As we chained vertices with WITHIN, the LIVES_IN label can point directly at the location we are looking for, or location several levels deeper
MATCH
	(person) -[:BORN_IN]-> () -[:WITHIN*0..]-> (us:Location {name:'United States'})
RETURN person.name
```

## Graph queries in SQL

Graph data can be represented with SQL, but with a challenge: In graph database, we traverse a number of edges to find the vertex we need, but the number of joins in SQL is not fixed in advance.

The idea of traversing paths in a query with SQL can be resolved with CTE. Below is an example:

```sql
with recursive
-- Get vertex ID and outgoing? incoming edges of node USA
-- in_usa is the set of vertex IDs of all locations within the United States
in_usa(vertex_id) as (
select
	vertex_id
from
	vertices v
where
	v.properties->>'name' = 'United States'
union
select
	e.tail_vertex
from
	edges e
join in_usa on
	e.head_vertex = in_usa.vertex_id
where
	e.label = 'within'
),
-- in_europe is the set of vertex IDs of all locations within Europe
in_europe(vertex_id) as (
select
	vertex_id
from
	vertices v
where
	v.properties->>'name' = 'Europe'
union
select
	e.tail_vertex
from
	edges e
join in_europe on
	e.head_vertex = in_europe.vertex_id
where
	e.label = 'within'
),
-- born_in_usa is the set of vertex IDs of all people born in the US
born_in_usa(vertex_id) as (
select
	e.tail_vertex
from
	edges e
join in_usa on
	e.head_vertex = in_usa.vertex_id
where
	e.label = 'born_in'
),
-- lives_in_europe is the set of vertex IDs of all people living in Europe
lives_in_europe(vertex_id) AS (
	SELECT e.tail_vertex FROM edges e
	JOIN in_europe ON e.head_vertex = in_europe.vertex_id
	WHERE e.label = 'lives_in'
)

SELECT v.properties->>'name' as name
FROM vertices v
-- join to find those people who were both born in the US *and* live in Europe
JOIN born_in_usa
 ON v.vertex_id = born_in_usa.vertex_id
```

[[Triple-Stores and SPARQL]]

[[Datalog]]