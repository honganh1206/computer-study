# Handling GET request
## Presentation layer
- The presentation layer **provides the entry point to our system**
- TODO: Create a reference to all projects in the solution from the main program
## Routing
Two ways of routing:
- Convention-based routing
- Attribute routing
### Convention-based routing
Consists of 3 parts:
- First part creates the mapping for **the controller name**
- Second part maps the action method
- Third part is used for optional parameter
![[Pasted image 20230718104708.png]]

### Attribute routing
- Used to map the routes directly to the action methods inside the controllers

```ad-tip
title: When to use different types of routing
While working with the Web API project, the ASP.NET Core team suggests
that we shouldn’t use Convention-based Routing, but Attribute routing
instead.

```

```ad-attention
title: Naming our resources
- The resource name in the URI should always be a noun and not an action e.g. **api/companies**
- When we createa route for a dependent entity, we should follow a slightly different convention: /api/principalResource/{principalId}/dependentResource.
```

## DTO classes and Entity Model classes

```ad-warning
title: Return entities in response
It is not a good practice to return entities in the Web API response and instead we should use Data Transfer Objects (DTOs)

```
### Benefits of using DTOs
- Remove any property or concatenate properties into a single property
### Record type
- A `record` type provides us an easier way to create an **immutable reference type** in .NET => `record` instance property values cannot change after its initialization
- `record` is a valid alternative to classes when we have to **send or receive data** => DTOs use `record` to transfer data from one part to another

---
# Global error handling

--- 
# Getting additional resources

```ad-done
title: Advantages of using a base class
When we use base `abstract` class for exception class (`NotFoundException`), we are not checking for specific class implementation but the base type

```

---
Method Safety & Method Idempotency
## Method safety
- Indicate whether that **method on a resource will have any side effects or not**
- A safe method only retrieves data and does not modify the state of the server
- Examples: `GET`, `HEAD`, `OPTIONS`, `TRACE`
## Method Idempotency
- Indicate that **making the same requests to the same resource should have the same effects as making a single request**
- Useful in scenarios when requests can be retried due to network issues/transient failures
- Examples: `GET`, `POST`, `DELETE`

---
# Working with PATCH request - Partial update

![[Pasted image 20230724172546.png]]
