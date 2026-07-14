In a different PID namespace we see different processes with `ps aux`

Default namespace/Host namespace: When we are outside a container, we are using the default namespace

Processes can have different combinations of namespaces e.g., network namespace but with other mount namespace

```bash
lsns -p 273 # -p for PID
```

Every process has 7 namespaces for cgroup - pid - ser - uts - ipc - mnt - net

Processes use their parent's namespace by default.

System calls for namespaces: `clone` (make a new process), `unshare` (disassociate context between child and parent process), `setns` (use an existing namespace)

> A kind of view/mapping for child process to trick it to see the root FS ("/") without seeing the host's real path like `/sys/fs/sandbox-123`
## PID namespaces

The same process has different PIDs in different namespaces.

Killing PID 1 is bad.

## User namespaces

A security feature for root in the container to be unprivileged.

In user namespace, UIDs are mapped to host UIDs in `/proc/self/uid_map`

## Network namespaces

Namespaces usually have two interfaces: **Loopback interface** for connections inside the namespace (127.0.0.1/88) and another interface for connections from outside.

Every server listens on a port and network interface e.g., 0.0.0.0:8080 means "port 8080 for every network interface in my namespace".

Physical network card = host network namespace.

Other namespaces are connected with the host namespace with a **bridge**

![[Network namespace.excalidraw]]