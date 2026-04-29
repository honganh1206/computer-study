In a triple-store, all information is stored in the form of three-part statements: (subject - vertex, predicate - edge, object - primitive data type/vertex) like "Jim likes bananas"

The object could be two things:
1. A primitive data type. We then have `(lucy, age, 33)` with `age` as the key and `33` as the value, which is a vertex `lucy` with property`{"age": 33}`
2. Another vertex. The subject is a tail vertex, the predicate the edge and the object the head vertex

## The semantic web

Core idea: Websites should publish information as machine-readable data for computers to read. We use the Turtle language for it.

```turtle
@prefix : <urn:example:>.
_:lucy
 a :Person;
 :name "Lucy";
 :bornIn _:idaho.
_:idaho
 a :Location; :name "Idaho";
 :type "state";
 :within _:usa.
_:usa
 a :Location; :name "United States"; :type "country"; :within _:namerica.
_:namerica a :Location; :name "North America"; :type "continent".
```

## The Resource Description Framework (RDF) data model

Sometimes RDF is written in an XML format.

```xml
<rdf:RDF
	xmlns="urn:example:"
	xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">
	<Location rdf:nodeID="idaho">
		<name>Idaho</name>
		<type>state</type>
		<within>
			<Location rdf:nodeID="usa">
				<name>United States</name>
				<type>country</type>
				<within>
					<Location rdf:nodeID="namerica">
						<name>North America</name>
						<type>continent</type>
					</Location>
				</within>
			</Location>
		</within>
	</Location>
	<Person rdf:nodeID="lucy">
		<name>Lucy</name>
		<bornIn rdf:nodeID="idaho"/>
	</Person>
</rdf:RDF>
```

## The SPARQL query language

SPARQL is a query language for triple-stores using the RDF data model.

