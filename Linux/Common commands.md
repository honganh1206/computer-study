
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

- Kill a process

```bash
# Using netstat to find the program
sudo netstat -tulpn | grep :4000

# Or using lsof for a detailed view
sudo lsof -i:4000
# Output
tcp   0   0 0.0.0.0:4000    0.0.0.0:*    LISTEN <PID>/node

# The gentle way - Send a SIGTERM signal asking the program to terminate gracefully
kill <PID>
# The forceful way - Send a SIGKILL signal asking the program to stop immediately without any cleaning up
kill -9 <PID>
```