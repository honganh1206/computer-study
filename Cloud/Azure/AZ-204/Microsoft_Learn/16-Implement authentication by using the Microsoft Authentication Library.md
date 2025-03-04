# Explore the Microsoft Authentication Library (MSAL)

- Provide ways to get tokens with a consistent APIs for many platforms
- Support many application types (Android, Angular, iOS and macOS, Node, etc.)
- Provide multiple authentication flows (Authorization code, client credentials, On-behalf-of, etc.)

## Public client and confidential client apps

### Public client

- Apps running on devices/desktop computers/web browser and cannot be trusted to safely keep app’s secrets => Only access web APIs on behalf of the user
- Do not have client secrets

### Confidential client applications

- Apps running on servers and difficult to access → Can hold configuration-time secrets

# Initialize client applications

## Initialize public & confidential client apps from code


```csharp
IPublicClientApplication app = PublicClientApplicationBuilder.Create(clientId).Build();

string redirectUri = "https://myapp.azurewebsites.net";
IConfidentialClientApplication app = ConfidentialClientApplicationBuilder.Create(clientId)
    .WithClientSecret(clientSecret) // Builder modifiers
    .WithRedirectUri(redirectUri )
    .Build();
```

# Interactive authentication with MSAL.NET


```csharp
using System;
using System.Threading.Tasks;
using Microsoft.Identity.Client;

namespace az204_auth
{
    class Program
    {
        private const string _clientId = "APPLICATION_CLIENT_ID";
        private const string _tenantId = "DIRECTORY_TENANT_ID";

        public static async Task Main(string[] args)
        {
            var app = PublicClientApplicationBuilder
                .Create(_clientId)
                .WithAuthority(AzureCloudInstance.AzurePublic, _tenantId)
                .WithRedirectUri("http://localhost")
                .Build(); 
            string[] scopes = { "user.read" };
            AuthenticationResult result = await app.AcquireTokenInteractive(scopes).ExecuteAsync();

            Console.WriteLine($"Token:\t{result.AccessToken}");
        }
    }
}
```