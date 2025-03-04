# User Creation
## Implementation
1. Create `AuthenticationController`
2. Create a Dto for user registration e.g. `UserForRegistrationDto`
3. Create mapping profile
4. Create service interface + service e.g. `IAuthenticationService` + `AuthenticationService` => Add `RegisterUser` method
5. Add authentication service to the service manager (Interface + implementation)

---
# Big picture

When the server validates the user’s credentials and confirms that the
user is valid, it’s going to send an encoded JSON Web Token (JWT) to the client.

![[Pasted image 20230808233205.png]]

### JWT

```ad-info
title: About JWT
A JSON web token (JWT) is a JavaScript object that can contain some attributes of the
logged-in user. It can contain a username, user subject, user roles, or some other useful information.

```

- JWT consists of **3 basic parts**:
	- Header
	- Payload
	- Signature

```ad-note
Every part of all three parts is shown in a different color. 

```

![[Pasted image 20230808233414.png]]


#### Header
The JWT header contains information like the type of token and the name of the
algorithm
```json
{
	"alg": "HS256",
	"typ": "JWT"
}
```

#### Payload

The payload contains some **attributes about the logged-in user**  e.g. the user id, the user subject, and information about whether a user is an admin user or not.

```ad-warning
JSON web tokens are not encrypted and can be decoded with any
base64 decoder, so please never include sensitive information in the
Payload

```

#### Signature
- The server uses the signature part to verify **whether the token contains valid information**, the information which the server is issuing
- The signature is **based on** a secret key that only the server knows

![[Pasted image 20230808234319.png]]


## Claims
### Definition
- Refers to **a piece of information about the entity** (typically a user) that is encoded within the JWT
- Used to **convey specific information** about the user or the token itself
## Types of claims

| Registered claims                                                         | Public claims                                                                                                       | Private claims                                                                                                                                       |
| ------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------- |
| - Predefined claims with standardized meanings </br> - Convey common info | - Custom claims defined by the app </br> - Convey additional info required by the app e.g. roles, permissions, etc. | - Custom claims agreed between parties using JWT </br> - Provide a way to communicate between two parties without conflicting with the public claims |
|                                                                           |                                                                                                                     |                                                                                                                                                      |


---
# Refresh token
- Sometimes we have a requirement not to force our users to log in every single time the token expires => Refresh token
- Refresh token = Credentials used to acquire new access tokens
![[Pasted image 20230812100315.png]]


## How it works
1. The client authenticates with the authentication component by providing the credentials
2. The authentication component issues the access + refresh token
3. The client requests the resource endpoint(s) with the access token
4. The resource validates the access token and provides the protected resource
5. Step 3&4 repeats until the access token expires
6. After the access token expires, the client requests a new access token by **providing the refresh token**
7. The authentication issues a new access token
8. Step 3 through 7 keep on repeating
9. After the refresh token expires, the client needs to authenticate with the authentication component again and repeat from step 1

```ad-warning
title: Adding new columns to AspNetUsers
1. When adding `RefreshToken` and `RefreshTokenExpiryDate` to the AspNetUsers table, remember to **keep only the `AddColumn` code parts that handle the `RefreshToken` and `RefreshTokenExpiryDate` in both `Up` and `Down` functions**
2. Revert the Ids of the `AspNetRoles` as previous before updating the database

```


--- 
