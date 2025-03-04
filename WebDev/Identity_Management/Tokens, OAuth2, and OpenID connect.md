# OAuth - Open standard for Authorization

- Delegates user authentication the **service that hosts the user's account** and **authorizes third-party applications to access that account**

## OAuth2 protocol

- With OAuth2, a client can **request an identity token next to the access token** and **use that id token to sign in the application** while **the application uses the access token to access the API**

# OpenID 
## How OpenID Connect generates Id Token

1. The client application creates a request which **redirects the user to the Identity Provider (IDP)**
2. The user proves the identity by **providing username and password** at the IDP level
3. IDP creates the Id token and **sends it back to the client**, and the token **contains user verification data**
4. The client application gets the Id token and validates it
5. The client application uses the Id token to **create claims identity** and **store these claims in a cookie**

![[Pasted image 20230906152023.png]]

## Types of clients

- A client **capable of maintaining the confidentiality of its credentials and can safely authenticate** => **Confidential client** such as ASP.NET Core MVC application (Secure the credentials on he server inaccessible to the user) vs. **Public client** (JS/mobile applications - Executed on the browser and cannot safely authenticate)

## Endpoints and Flows

This course focuses on **Authorization Code Flow with Proof Key for Code Exchange (PKCE)**


## Authorization Code Flow


![[Pasted image 20240509140102.png]]

### Steps

1. User tries to login or access the protected page
2. The client sends an authorization request to the `/authorization` endpoint with the `response_type` code + params 
3. Identity provider shows the login page
4. User authenticates + gives consent to IDP
5. IDP replies with a **code** (Authorization Code Flow) via URI re-direction/Form POST
6. The client calls the `/token` endpoint through the back channel by providing the code + client id + client secret
7. IDP validates the code + client credentials
8. IDP issues the id token + access token (refresh token as well if requested)
9. Client app uses the access token + attach it to the HTTP request as a `Bearer` token for verification process against the WebAPI
10. Web API replies after it successfully validates the token