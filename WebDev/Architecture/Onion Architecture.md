# Definition

- Consists of 4 layers:
	- Domain/Core layer
	- Service Layer
	- Infra Layer
	- Presentation layer

![[Pasted image 20230716161742.png]]

## Domain/Core layer
- Contain the most crucial and fundamental business logic
- Be independent of external frameworks/dependencies to be testable/reusable
- Defines the business models, entities, business rules, etc.
## Application/Service Layer
- Sits around the Core
- Serve as an intermediary between the Core and the external layers (user interface/API)
- Contains use cases, app services, or app-specific workflows
## Infra Layer
- Wraps the external dependencies and infra-related concerns like db, web services, external APIs
- Provides **implementations** for interfaces defined in Domain + Service layer
- Responsible for database access, communication with external systems, and other technical aspects
## User Interface/Presentation Layer - Outermost layer
- Interact with users or external systems
- Should be web app, desktop app, mobile app, etc.
- Should be **as thin as possible**
- **Delegate most of the business logic to the Service layer**
---
# Advantages of Onion architecture

- All layers interact with each other strictly through the interfaces defined in the layers below
- Follow the method of coding to interfaces and not implementations
- We can create an interface for an external system/service
- Fosters better separation of concerns, maintainability, and flexibility.
- Allows us to swap out implementations in the Infrastructure layer or the User Interface layer without affecting the Core business logic.
---
# Flow of dependencies

- The deeper the layer resides inside the Onion, the fewer dependencies it has => Dependencies flow inward
- The outer layers are all allowed to reference the layers that are **directly below them** in the hierarchy