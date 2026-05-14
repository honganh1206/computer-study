A virtualization technique that assigns a dedicated, physical graphics card directly to a virtual machine (VM). This is commonly called “VFIO” (Virtual Function I/O)

GPU passthrough works best with **QEMU** paired with **KVM** (Kernel-based Virtual Machine), a Linux-based virtualization tool that enables near-native performance.

**Firecracker is too minimal for GPU passthrough** because it strips away the complex device emulation (like PCI buses and BIOS) that a GPU requires to function

Requirements:

1. **Hardware Virtualization**: Your CPU must support virtualization extensions:
    - Intel: **VT-d** for Directed I/O.
    - AMD: **AMD-Vi** for IOMMU (Input-Output Memory Management Unit).
2. **GPU**: Ideally, you’ll have **two GPUs**—one for the host system and one dedicated to the VM. This prevents your host from losing graphics capability when the GPU is passed through.
3. **Operating System**: GPU passthrough works best on **Linux** with **QEMU and KVM**. You can use Ubuntu, Fedora, or any other modern Linux distribution that supports KVM.
4. **BIOS Settings**: Enable virtualization and IOMMU support in your BIOS or UEFI settings. This is usually under “Advanced” or “Chipset” settings.
5. **Drivers and Configuration**: Ensure your host has the appropriate GPU drivers and the VFIO (Virtual Function I/O) kernel modules installed to support passthrough.

Steps:

1. Enable IOMMU in BIOS
2. Configure IOMMU in Linx with boot params
3. Identify GPU info
4. Launch QEMU with GPU passthrough

