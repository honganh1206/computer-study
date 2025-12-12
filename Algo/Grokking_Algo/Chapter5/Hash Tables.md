
# Hash functions

```ad-summary
title: Benefits
Hashes are good for:
- Modeling relationships from one thing to another thing
- Filtering out duplicates
- Caching/Memorizing data instead of making the server do work

```


- A function **where you put in a string and you get back a number**

![[Pasted image 20231028213817.png]]

- Requirements:
	- **Consistency**: Every time you put in “apple”, you should get “4” back.
	- **Need to map different words to different numbers**: A hash function is no good if it always returns “1” for any word you put in. 

- Hash function + Array = Hash table/Hash maps/maps/dictionaries/associative arrays

## How things work under the hood

Scenario: Supposed you were given a list of students' names (Keys) and their grades (Values)

1. **Hash** the students' names: Use **hash functions** to turn students' names into unique hash codes
2. Associate each code with **a slot in an array**: Each code would refer to a *memory location/index in an array* and the array uses that code to look up for the key
3. Store the values inside the slots corresponding to a key
4. Retrieve values: To retrieve a student's grade, hash their name to get the code and look it up the table to retrieve the associated grade


## Use cases

- Phone number lookups
- Mapping a web address to an IP address (DNS resolution)
- Caching (websites remember the data instead of re-calculating it)

```python
cache = {}

def get_page(url):
	if cache.get(url):
		return cache[url]
	else:
		data = get_data_from_server(url)
		cache[url] = data
		return data
```


---

# Collisions

- Definition: Two keys have been assigned to the same spot
- Lessons:
	1. *Your hash function is really important*: Ideally, your hash function would map keys **evenly** all over the hash.
	2. *Use a good hash function will NOT slow down the hash tables*
- Solutions:
	- A low load factor (Number of items in hash table/Total number of slots)
	- A good hash function

# Performance

- Best case/Average case - $O(1)$
- Worst case - $O(n)$

![[Pasted image 20231029211519.png]]

## Load factor

- Rule of thumb:
	- Create a new array twice the size of the old one to reduce load factor
	- Resize when your load factor is > 0.7

## Good hash function

- A good hash function **distributes values in the array evenly** >< A bad hash function **groups values together and produces a lot of collisions**



---

# Exercises

5.5. C & D

5.6. B & D

5.7. B, C and D