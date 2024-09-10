# Docker Overview
### Install Docker Engine on Ubuntu/WSL2 (without Docker Desktop)

- [Script to install](https://gitlab.com/bmcgonag/docker_installs)
- Install Docker Engine on WSL2 based on the [Docker docs on installation on Ubuntu](https://docs.docker.com/engine/install/ubuntu/)


```bash
# Add Docker's official GPG key:
sudo apt-get update
sudo apt-get install ca-certificates curl
sudo install -m 0755 -d /etc/apt/keyrings
sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc
sudo chmod a+r /etc/apt/keyrings/docker.asc

# Add the repository to Apt sources:
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu \
  $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
sudo apt-get update


# install packages
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
```

- Get docker to run as root user (from this [link](https://github.com/rancher-sandbox/rancher-desktop/issues/1156#issuecomment-1017042882))

```bash
# Run docker without sudo
sudo chown root:docker /var/run/docker.sock
sudo chmod g+w /var/run/docker.sock
sudo gpasswd -a $USER docker
sudo systemctl start docker

# Then reload WSL2
```
## Keeping local environment clean


- Free up some space with `docker image prune -f` or [more commands here](https://docs.docker.com/config/pruning/#:~:text=Prune%20everything,system%20prune%20to%20prune%20volumes.&text=y%2FN%5D%20y-,By%20default%2C%20you're%20prompted%20to%20continue.,f%20or%20%2D%2Dforce%20flag.)

## [Docker Cheatsheet](https://sweworld.net/cheatsheets/docker/)

## [Move Docker data to another drive](https://stackoverflow.com/questions/62441307/how-can-i-change-the-location-of-docker-images-when-using-docker-desktop-on-wsl2)

