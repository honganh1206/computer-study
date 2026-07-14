# K3S configs
Only server node can use kubectl

Relevant paths: /etc/rancher, /var/lib/rancher/k3s

K3S paths at server node:
/etc/rancher/k3s/k3s.yam (kubeconfig file)
/etc/rancher/node/password
/etc/systemd/system/k3s.service
/etc/systemd/system/k3s.service.env
/var/lib/rancher/k3s/agent (root-restricted)
/var/lib/rancher/k3s/data (busybox related binaries of command tools)
/var/lib/rancher/k3s/server (server functionalities)
/var/lib/rancher/k3s/server/token (self-generated token for auth)
/var/lib/rancher/k3s/server/manifests (YAML manifests configuring services and resources like Traefik services)

K3S paths at agent nodes:
/etc/rancher/node/password
/etc/systemd/system/k3s-agent.service
/etc/systemd/system/k3s-agent.service.env
/var/lib/rancher/k3s/agent (functionalities)
/var/lib/rancher/k3s/data (busybox)