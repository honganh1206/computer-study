[[MapReduce]]

MapReduce is a combination of declarative query language and imperative query API.

Example with MongoDB MapReduce

```js
db.observations.mapReduce(
	// Call once for every document that matches query
	function map() {
		var year = this.observationTimestamp.getFullYear();
		var month = this.observationTimestamp.getMonth() + 1;
		emit(year + "-" + month, this.numAnimals);
	},
	// Group key-value pairs and execute reduce() once for each key
	function reduce(key, values) {
		return Array.sum(values);
	},
	{
		// Consider only shark species
		query: { family: "Sharks" },
		out: "monthlySharkReport"
	}
);
```

MapReduce is often used for distributed execution on a cluster of machines, and SQL can be implemented as a pipeline of MapReduce operations.