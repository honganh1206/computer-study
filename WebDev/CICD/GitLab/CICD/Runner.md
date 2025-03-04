---
tags:
  - "#study"
---
# Runner

## Installation & Activation

- Shared runner: Configure in Settings > CI/CD > Runners > Instance runners
- Project runner:
    - Docker version: Follow [this guide with the local volume mounts version](https://docs.gitlab.com/runner/install/docker.html) 
    - Binary version (Not recommended as there might be a need for .yml configuration):

```bash
# Download the binary for your system
sudo curl -L --output /usr/local/bin/gitlab-runner https://gitlab-runner-downloads.s3.amazonaws.com/latest/binaries/gitlab-runner-linux-amd64

# Give it permission to execute
sudo chmod +x /usr/local/bin/gitlab-runner

# Create a GitLab Runner user
sudo useradd --comment 'GitLab Runner' --create-home gitlab-runner --shell /bin/bash

# Install and run as a service
sudo gitlab-runner install --user=gitlab-runner --working-directory=/home/gitlab-runner
sudo gitlab-runner start

```

## Registration

- [Follow this guide with the Docker/local volume mounts version](https://docs.gitlab.com/runner/register/index.html?tab=Docker)
- Common issues:
	- [Install nano inside docker exec shell](https://stackoverflow.com/questions/30853247/how-do-i-edit-a-file-after-i-shell-to-a-docker-container)
	- [Resolve "Cannot connect to Docker dameon on Gitlab"](https://stackoverflow.com/questions/61105333/cannot-connect-to-the-docker-daemon-at-tcp-localhost2375-is-the-docker-daem)
	- Change `privileges` property inside `/etc/gitlab-runner/config.toml` to `true` and restart gitlab-runner container


>[!warning]
Legacy Git repositories create a _master_ branch by default, while newer ones use _main_. Use the branch name that matches your local Git repository by using `git show-ref` to check if the local branch name is `refs/heads/master` or `refs/heads/main`