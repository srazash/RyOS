# RyOS

## Welcome to the Operating System of tomorrow (assuming global nuclear war breaks out today)...

![](OK.png)

*RyOS v0.0.1 indicating that it's "OK"... nobody truly knows what's Othis means, but there is a general sense of calm and inner peace as a result of it. Thank you, RyOS.*

RyOS is a feature-poor, barely functioning operating system that provides zero in the way of security, stability or scalability. It's bleeding edge, non-existent file system can hold literally no data whatsoever, entirely negating the risk of any possible data loss or corruption, its next-generation kernel is a joke and doesn't really exist right now. Oh, and I make no promises about not bricking your expensive hardware... In other words, this is a hobby project which if ever compiled and run should **ONLY be run on a virtual machine**, and even then I make no promises.

## How to make work, sort of...

Build the Docker image to compile my trash source code (this only needs to be done once and it can take a while):

```
docker build buildenv -t ryos-buildenv
```

Spin up a docker container from the image we just built:

```
docker run --rm -it -v "${pwd}:/root/env" ryos-buildenv
```

Once the container is up and running, build the OS using the Make:

```
make build-x86_64
```

Once done kill the contained with the ```exit``` command. This will produce a bootable ISO image in the dist/x86_64/ directory. This works on Hyper-V and an aging Lenovo x201 I have - again, I stress, don't use this on bare metal yourself!

## Credit

I am responsible for none of this, all credit goes to the CodePulse YouTube channel whose [video series](https://www.youtube.com/playlist?list=PLZQftyCk7_SeZRitx5MjBKzTtvk0pHMtp) I am following closely in order to do any of this.