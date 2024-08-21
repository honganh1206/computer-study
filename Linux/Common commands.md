
- Make a `.sh` file executable 

```bash
chmod u+x YourScriptFileName.sh
```

- Free up some space

```bash
sudo apt-get autoremove # Remove apt dependencies that are no longer dependencies
&& sudo apt-get autoclean  # Clear local cache of package files that can no longer be downloaded
&& sudo journalctl --rotate # mark all journal logs as archived
&& sudo journalctl --vacuum-size=100M # Limit journal logs to 100mb
```

- Install .deb packages

```bash
dpkg -i package.deb
```


- [Free up some space](https://itsfoss.com/free-up-space-ubuntu-linux/)

- Check all groups with `id`

