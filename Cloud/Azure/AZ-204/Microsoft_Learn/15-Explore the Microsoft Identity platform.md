## Definition

- Help you build applications your users and customers can sign in **using their Microsoft identities or social accounts**
- Provide authorized access to your own APIs or Microsoft APIs
- Components:
	- OAuth 2.0 and OpenID Connect
	- Open-source libraries
	- Microsoft identity platform endpoint
	- Application management portal
	- App config API and PowerShell

## Service principals

> [!summary]
> - When we register an application with a Microsoft Entra tenant, we create an application object & service principal object in the home tenant. 
> - An application object serves as a template to create multiple service principals to handle access to the resources and actions of a tenant.
> - A service principal represents an application for access to resources secured by a tenant
> 

- To delegate Identity and Access Management functions to Microsoft Entra ID, an application must be **registered with a Microsoft Entra tenant**.
- Register your app with Microsoft Entra ID = Create an **identity configuration** for your app to integrate with MEID
- When your register your app in the portal, an **application object** (the globally unique instance of the app coming with a globally unique ID) and a **service principal object** are automatically created in your home tenant.

### Application object

- An application object is used as a **template or blueprint** to create one or more service principal objects.
- A service principal is created in every tenant where the application is used.
- The application object describes 3 aspects of an app:
	- How the service can issue access tokens
	- Resources for the application
	- Actions the app can take

### Service principal object

- To access resources secured by a Microsoft Entra tenant, the entity that requires the access must be represented by a security principal
- The security principal **defines the access policy and permissions** for the user/application in the Microsoft Entra tenant
- Three types:
	- Application: The local application instance of a global application object in a single tenant/directory
	- Mananged identity: Represent a managed identity that provides an identity for apps to use
	- Legacy: Represent a legacy app created before app registrations were introduced

### Relationship between application objs and service principals

- While the application obj is the **global** representation of your app across all tenants, the service principal is the **local** representation in a single tenant
- An application object has a **one to one** relationship with the software application and a **one to many** relationships with its service principals
- A single-tenant application has only one service principal in its home tenant, while a multitenant application has a service principal in each tenant where a user from that tenant consented to its use

## Permissions and consent

> [!summary]
> 
> - Permissions can be chunked into small sets (scopes) and third-party apps or users can request only the permissions that they need.
> - Permissions could be delegated to apps requiring a signed-in user to consent to the permissions, or permissions can be app-only e.g., background services, daemons.
> - Apps require either static user consent (up-front permissions), incremental and dynamic user consent or admin consent for highly privileged data.

### Permissions

- The Microsoft identity platform implements the [OAuth 2.0](https://learn.microsoft.com/en-us/azure/active-directory/develop/active-directory-v2-protocols) authorization protocol
- Any web-hosted resource/3rd-party resources that integrates with the Microsoft identity platform has a resource identifier, or _application ID URI_.
- When a resource's functionality is chunked into small permission sets (scopes), third-party apps can be built to **request only the permissions that they need** to perform their function.
- Apps request permissions in the `scope` query parameter, represented as a string value e.g., `https://graph.microsoft.com/Calendars.Read` 
- Some high-privilege permissions can be granted only through administrator consent endpoint.

#### Types of permission

- Delegated permissions: For apps that have a **signed-in user present** => Either the user or an administrator consents to the permissions the app requests
- App-only access permission: For apps without a signed-in user (background services, daemons, etc.) => Only an administrator can consent

### Consents

- Apps in Microsoft Identity platform rely on consent to gain access to necessary resources or APIs
- Three types of consent: 
	- Static user consent
	- Incremental and dynamic user consent
	- Admin consent

#### Static user consent

- Need to specify all permissions in the app’s config in the Azure portal
- Static permissions enable administrators to consent on behalf of all users in the organization
- Drawbacks:
	- The app requires all permissions it needs upon the user’s first sign-in => Discourage end-users
	- Need to know all resources it would access ahead of time

#### Incremental and dynamic user consent

- Ask for minimum set of permissions upfront and request more over time by **including the new scopes in the `scopes` parameter** when requesting an access token

> [!tip]
> 
> If you require admin privileged permissions or if your app uses dynamic consent, **you must register all of the permissions in the Azure portal** (not just the subset of permissions that require admin consent). This enables tenant admins to consent on behalf of all their users.

#### Admin consent

- Required when your app needs access to certain high-privilege permissions => Ensure admins have other controls before authorizing apps or users to highly privileged data

> [!note]
> 
> Admin consent done on behalf of an organization still requires the static permissions registered for the app.

### Requesting individual user consent

```http
GET https://login.microsoftonline.com/common/oauth2/v2.0/authorize?
client_id=6731de76-14a6-49ae-97bc-6eba6914391e
&response_type=code
&redirect_uri=http%3A%2F%2Flocalhost%2Fmyapp%2F
&response_mode=query
&scope=
https%3A%2F%2Fgraph.microsoft.com%2Fcalendars.read%20
https%3A%2F%2Fgraph.microsoft.com%2Fmail.send
&state=12345
```

- The `scope` parameter is a space-separated list of delegated permissions that the app is requesting.
- Each permission is indicated by appending the permission value to the resource's identifier (the application ID URI) like read user’s calendar and send mail as the user


## Conditional access

> [!summary]
> 
> Conditional Access works as a policy to provide service protection. When an user signs in, the policy is invoked for the user to perform additional authentication factors e.g., MFA, fingerprint, one-time password, etc.

Conditional access enables service protection in several ways:

- MFA
- Allowing only Intune enrolled devices to access specific services
- Restricting user locations and IP ranges

### How?

- When an app requests a token for a service, the app requires code changes to handle Conditional Access challenges
- Conditional Access policies can be applied to the app and also a web API your app accesses

### Examples 

- Building a single-tenant iOS app and apply a Conditional Access policy => When an user signs in, the policy is invoked for the user to perform MFA
- Building an app that uses a middle tier service (e.g., gateway service) to access a downstream API (e.g., API to retrieve personal information) => When an user signs in, the middle tier performs on-behalf-of flow to request access to the downstream API. At this point, the API issues a claims "challenge" to the middle tier. The middle tier sends the challenge back to the app for additional authentication factors.