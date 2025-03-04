
## Configure application settings

- For **Linux apps and custom containers**, App Service passes app settings to the container using the `--env` flag to set the environment variable in the container.

> [!info]
> 
> The values in App Service override the ones in _Web.config_ or _appsettings.json_


- For ASP.NET and ASP.NET Core developers, the values you set in App Service override the ones in _Web.config_.

## Configure general settings

- Stack settings: Software stack to run the app (languages, SDKs, etc.) => **Optional startup commands** for Linux/container apps
- Platform settings: Configure settings for the hosting platform (bitness, WebSocket protocols, etc.)
- Debugging: Enable **remote debugging** for ASP.NET/ASP.NET Core/Nodejs (Turn off automatically after 48 hours)
- Incoming client certs: Require client certs in mutual authentication
## Configure path mappings

- Configure in **Configuration > Path mappings**
- Path mappings page displays **different options based on the selected OS**

## Enable diagnostic logging

- Go to **Monitoring > App Service logs** and enable application logging

## Configure security certificates


- The free **App Service managed certificate** and the **App Service certificate** already satisfy the requirements of App Service.