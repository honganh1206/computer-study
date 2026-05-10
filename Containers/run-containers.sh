set -eux

# Fish docker container flattened to a single tarball
wget bit.ly/fish-container -O fish.tar

mkdir container-root
cd container-root
tar -xf ../fish.tar

# Generate random cgroup (organize processes into hierarchical groups) uuid
uuid="cgroup_$(shuf -i 1000-2000 -n 1)"
cg_path="/sys/fs/cgroup/$uuid"
# Create the cgroup directory
sudo mkdir -p "$cg_path"

# 2. Assign limits (Cgroup v2 syntax)
# cpu.shares (v1) is now cpu.weight (v2). Formula: (shares * 100) / 1024
echo 50 | sudo tee "$cg_path/cpu.weight" >/dev/null
# memory.limit_in_bytes (v1) is now memory.max (v2)
echo 1000000000 | sudo tee "$cg_path/memory.max" >/dev/null

# A lot of work:
# 1. Use new cgroup
# 2. unshare: make and use new PID, network, hostname, and mount namespace
# 3. chroot: change root dir "/" to current dir, like a mini root system
# 4. mount: use /proc (virtual filesystem to expose internal state like status, file descriptor, etc.) in new mount namespace
# 5. hostname: change the hostname in the new hostname namespace
# NOTE: This is for cgroup v1
# cgexec -g "cpu,cpuacct,memory:$uuid" \
#   unshare -fmuipn --mount-proc \
#   chroot "$PWD" \
#   /bin/sh -c "/bin/mount -t proc proc /proc && hostname container-test && /usr/bin/fish"

# 3. Use the cgroup
# We move the current shell's PID into the cgroup.procs file of the target group
# before running the unshare/chroot commands.
sudo sh -c "echo $$ > $cg_path/cgroup.procs && \
  unshare -fmuipn --mount-proc \
  chroot . \
  /bin/sh -c '/bin/mount -t proc proc /proc && hostname container-test && /usr/bin/fish'"
