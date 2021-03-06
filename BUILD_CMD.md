# Windows / PowerShell

```sh
# from powershell
docker run --rm -it -v "${pwd}:/root/env" ryos-buildenv # entering bash environment in docker container

# from bash
make build-x86_64
# assuming no errors compiling
exit # returning to powershell environment

# from powershell
qemu-system-x86_64 -L "C:\program files\qemu" -cdrom dist/x86_64/kernel.iso
```