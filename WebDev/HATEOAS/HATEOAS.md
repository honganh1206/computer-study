# Hypermedia as the Engine of Application State - HATEOAS
## Hypermedia 
- Any kind of content that contains **links to media** such as docs, images, videos, etc.
- REST architecture allows us to **generate hypermedia links in our responses dynamically**

## Links
- A link is  "a typed connection between two resources that are identified by Internationalised Resource Identifiers (IRIs)" => We use links to **traverse the internet or the resources on the internet**
- A link consists of
	- `href` - target URI
	- `rel` - link relation type (how the current context is related to the target resources)
	- `method` - HTTP method to know how to distinguish the same target URIs

## Pros/Cons of HATEOAS

- Pros:
	- Self-discoverable and explorable APIs
	- A client can use the links to implements its logic
	- The server drives the application state and URL structure
	- The link relations can be used to point to dev's docs
	- Versioning through hyperlinks becomes easier
	- Reduced invalid state transaction calls
	- Evolvable APIs

```ad-warning
title: HATEOAS and Data Shaping
When we generate links, **HATEOAS strongly relies on having the ids available** to construct the links for the response

```


## Implementation

### Models/Entities
- Add `Links` model + `LinkResourceBase` (Store a list of links) + `LinkCollectionWrapper` (Presentation purposes) 
- Add `DynamicEntity` model to handle different models
- Add `LinkParameters` class to wrap the `EmployeeParameters` class with the `HttpContext` to check the headers
- Change XML writing method to handle Href + Rel + Method
- Create a `LinkResponse` class to handle linked/shaped entities

### Data Shaping
- Modify `DataShaper` to get the Id separately

### Service
- Create a service to handle custom media types e.g. json, xml in the headers
- Implement the `EmployeeLinks` class to generate links
- Modify Service + Controller class to use `LinkResponse` class

### Validation
- Add a validation filter for HATEOAS headers