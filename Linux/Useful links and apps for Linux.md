## Install Ubuntu & Configs

```cmd
wsl --list
wsl --install
wsl --unregister Ubuntu
```

- Common issues to deal with when installing:

    - [Windows Subsystem for Linux 2: Temporary failure resolving 'archive.ubuntu.com'](https://askubuntu.com/questions/1450120/windows-subsystem-for-linux-2-temporary-failure-resolving-archive-ubuntu-com)
    - [System has not been booted with systemd as init system (PID 1). Can't operate](https://askubuntu.com/questions/1379425/system-has-not-been-booted-with-systemd-as-init-system-pid-1-cant-operate)
    - [Cannot connect to docker daemon/Start docker whenver Ubuntu WSL2 is run](https://stackoverflow.com/questions/44678725/cannot-connect-to-the-docker-daemon-at-unix-var-run-docker-sock-is-the-docker)

```bash
# Resolve archive ubuntu failure
sudo rm /etc/resolv.conf
sudo bash -c 'echo "nameserver 8.8.8.8" > /etc/resolv.conf'
sudo bash -c 'echo "[network]" > /etc/wsl.conf'
sudo bash -c 'echo "generateResolvConf = false" >> /etc/wsl.conf'
sudo chattr +i /etc/resolv.conf

# Integrate systemd
sudo nano /etc/wsl.conf

# Edit the file to this
[boot]
systemd=true
```


## Useful Linux commands

```bash
sudo update-alternatives --config editor # change default editor
sudo update-alternatives --config x-terminal-emulator # change default terminal emulator
```

## [Edit mount points at startup](https://www.reddit.com/r/PleX/comments/11jjg8e/comment/k4iwpwh/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button)

## Dual-booting Windows and Linux

```
# On Linux
timedatectl set-local-rtc 1 --adjust-system-clock

# On Windows
Reg add HKLM\SYSTEM\CurrentControlSet\Control\TimeZoneInformation /v RealTimeIsUniversal /t REG_QWORD /d 1
```

## Cool applications to install

- GSmartControl
- Disk Usage Analyzer
- Synaptic Package Manager
- Tweaks (for Ubuntu GNOME)
- Tmux and [how to use it](https://hamvocke.com/blog/a-quick-and-easy-guide-to-tmux/) and some common commands:
	- Open a new pane vertically `Ctrl b + %`
- Vim and [this game-based tutorial](https://vim-adventures.com/)
- Vitals for GNOME (display specs)
- Okular (Way better than any default PDF readers out there!)

