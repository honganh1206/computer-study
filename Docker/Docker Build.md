
## [Docker build cache](https://docs.docker.com/build/cache/)

### How the build cache works

When a layer changes (changes to a file/configs/etc.), the layers that come after it are also affected

![[Pasted image 20240608105944.png]]

### Refactor Dockerfile to optimize the build cache

#### 1. Order your layers

- For JS, we can make 2 `COPY` commands, one for the code and one for the dependencies

```dockerfile
# syntax=docker/dockerfile:1
FROM node
WORKDIR /app
COPY package.json yarn.lock .    # Copy package management files
RUN npm install                  # Install dependencies
COPY . .                         # Copy over project files
RUN npm build                    # Run build
```

#### 2. Keep your layers small

- Do not include unnecessary files (logs, artifacts, previous builds, etc.)
- Use your package manager wisely

#### 3. Use appropriate base images


#### 4. Use multi-stage builds


#### 5. Combine commands together whenever possible

```dockerfile
RUN echo "the first command" && echo "the second command"
# or to split to multiple lines
RUN echo "the first command" && \
    echo "the second command"
```