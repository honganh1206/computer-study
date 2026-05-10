## What we needs

Fast startup time -> Warm up sandbox

Filesystem persistence?

Persistent sandbox (fetch new changes each 30 mins?)

Control layer

Image registry for repo?

## Options

1. Firecracker (strong isolation)
2. gVisor (intercept system calls between containers and host kernel, run as containers, faster startup but add over head + share kernel with host)
3. Kata (container runtime using microVMs, bridge between containers and VMs)
4. Modal (use gVisor at their core)
5. E2B (follow microVM approach)

Comparison between ease of implementation vs. strong isolation

|Aspect|gVisor|Firecracker|
|---|---|---|
|Kernel|shared (mediated)|separate|
|Isolation boundary|syscall layer|VM boundary|
|CPU|shared|shared (virtualized)|
|RAM|shared (isolated by OS)|isolated (VM memory)|
|Filesystem|bind mount|disk / clone / image|
|Networking|simple|manual setup|
|Startup|very fast|slower|
|Complexity|low|high|

## Suggested structure

```
Kubernetes (scheduler + API)
   ↓
containerd (run container on each node)
   ↓
Kata Containers
   ↓
Firecracker microVMs (VM engine)
```

SSH should be for debugging, not the control interface for agents. Make sandbox APIs (daemon to handle requests with sandboxd service  to handle requests and streaming output?)

Clone repo inside VM, alternative is mount/copy/sync from host

Ephemeral sandbox (I prefer long-running with polling image clone) is the suggested approach, then move on to warm pool / cached images / snapshots

Use Kata to keep micro VMs isolated when moving to k8s

How the server should look like 

```
[ Firecracker VM ]
  ├── sandboxd (HTTP/gRPC server)
  ├── /workspace
  └── OS
```

Lifecycle: `create → exec → exec → exec → destroy`
## Questions

Agents need a way to access mounted files on VM? Not just sandboxd service? File operations maybe?

If I use k8s + kata, does that lead to multiple layers? Like pod -> VM -> container? -> K8S creates pod with `runtimeClass = kata` -> containerd calls `kata-runtime` -> Kata spins up VM by launching Firecracker -> Run containers (sandboxd) inside VM