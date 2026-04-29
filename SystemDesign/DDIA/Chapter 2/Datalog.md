A foundation for later query languages like SQL, SPARQL and Cypher to build upon.

Syntax : `predicate(subject, object)`

```d
name(namerica, 'North America').
type(namerica, continent).
name(usa, 'United States').
type(usa, country).
within(usa, namerica).
name(idaho, 'Idaho').
type(idaho, state).
within(idaho, usa).
name(lucy, 'Lucy').
born_in(lucy, idaho).
```

Datalog is a subset of Prolog. We define rules that tell the database about new predicates.

```d
 /* Rule 1 */
within_recursive(Location, Name) :- name(Location, Name).

/* Rule 2 */
within_recursive(Location, Name) :- within(Location, Via),

 /* Rule 3 */
within_recursive(Via, Name).
migrated(Name, BornIn, LivingIn) :- name(Person, Name),
									born_in(Person, BornLoc),
									within_recursive(BornLoc, BornIn),
									lives_in(Person, LivingLoc),
									within_recursive(LivingLoc, LivingIn).

?- migrated(Who, 'United States', 'Europe').
/* Who = 'Lucy'. */
```