# RyOS

## Say goodbye to RyOS, and say hello to **RyOS64**, truly the Operating System of a *64-bit* tomorrow!

![](Glitch64.gif)

RyOS64 is a feature-poor, barely functioning operating system that provides zero in the way of security, stability or scalability. It's bleeding edge, non-existent file system can hold literally no data whatsoever, entirely negating the risk of any possible data loss or corruption, its next-generation kernel is a joke and doesn't really exist right now. And all of this is in glorious, full colour, 64-bit! Oh, and I make no promises about not bricking your expensive hardware... In other words, this is a hobby project which if ever compiled and run should **ONLY be run on a virtual machine**, and even then I make no promises.

![RyOS64 version 0.0.3 smooth talking you like some chad. RyOS64, please.](OKv3.png)

*RyOS64 version 0.0.3 smooth talking you like some chad. RyOS64, please.* 😳

## How to make work, sort of...

Build the Docker image to compile my trash-tier source code (this only needs to be done once and it can take a while):

```sh
# any os
docker build buildenv -t ryos-buildenv
```

> Refer to the included Dockerfile to see the exact recipe for this image, but it basically boils down to the GCC toolchain and NASM for making things actually do stuff, and Xorriso and GRUB tools for producing a bootable ISO.

Once the image is built it can be loaded into a running container using this command:

```sh
# windows/cmd
docker run --rm -it -v "$pwd":/root/env ryos-buildenv

# windows/powershell
docker run --rm -it -v "${pwd}:/root/env" ryos-buildenv

# linux/bash
docker run --rm -it -v "%cd%":/root/env ryos-buildenv

# macos/zsh
docker run --rm -it -v "%cd%":/root/env ryos-buildenv
```

> Please note I'm working on Windows and using PowerShell to drive the bulk of this, please tweak these instructions based on your environment.

Once the container is up and running, build the OS using ```make```:

```sh
# any os
make build-x86_64
```

Once done kill the container with the ```exit``` command. This will produce a bootable ISO image in the dist/x86_64 directory. This works on Hyper-V, QEMU and an aging Lenovo x201 I have - again, I stress, **do not use this on bare metal yourself!**

## Booting the ISO in QEMU

Once built, there will be a bootable ISO image in the dist/x86_64 directory, this can (and probably should) be booted in a virtual machine. As running Docker seems to cause some issues with Hyper-V on the same Windows host, I would recommend using QEMU - on windows you will need to provide an extra argument (`-L`) when launching AND check that the QEMU folder is added to the path. Things should be a bit smoother on Linux/Mac but I have not tested this.

```sh
# windows
qemu-system-x86_64 -L "C:\program files\qemu" -cdrom dist/x86_64/kernel.iso

# linux / macos
qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso
```

## RyOS64 version history

- 0.0.1: Boots and prints "OK"
- 0.0.2: Boots and prints "OK", but it does it in full 64-bit mode! Recrowned as **RyOS64**.

![RyOS64 version 0.0.2](OK.png)

*RyOS64 version 0.0.2*

- 0.0.3: Boots and prints "RyOS64: OK, baby!"
- 0.0.4 ???
- ...
- 1.0.0 **?????**

_*all planned features are subject to change._

## Credits

I am responsible for none of this, all credit goes to the CodePulse YouTube channel whose [video series](https://www.youtube.com/playlist?list=PLZQftyCk7_SeZRitx5MjBKzTtvk0pHMtp) I am following closely in order to do any of this.