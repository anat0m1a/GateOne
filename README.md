# GateOne Password Manager

## What is this?

This program was created for an exercise during my probation period at my workplace. It is a CTF containing multiple flags, which can be found by statically analysing the binary.

I recommend not reading the source code if you want a challenge :)

## How do I start?

First, you'll want to make sure you have all the tools you need. Make sure you have some kind of disassembler, I recommend [Ghidra](https://github.com/NationalSecurityAgency/ghidra/releases). If you're new to disassemblers, I recommand looking at a quick reference pdf online or finding a short intro course that teaches you the basics.

You'll also need some sort of Unix environment unless you want to end up building C on Windows, which I don't recommend. If you're using Windows as your host, I recommend installing [WSL](https://learn.microsoft.com/en-us/windows/wsl/about). If you'd like to use a VM, an easy way to do this is to use [VirtualBox](https://www.virtualbox.org/) or [VMware Workstation Player](https://www.vmware.com/products/workstation-player.html) to install [Ubuntu](https://ubuntu.com/download/desktop) or something akin to it.

Once you're up and running with whatever environment you choose, run the command `which gcc`, to make sure you have a C compiler ready to go.

If not and you're running ubuntu, run the following command:
`sudo apt install build-essential`

To compile the binary run the following command:
`gcc passwordman.c enterDatabase.c bobLoop.c userLoop.c -o passwordMan`

## How will I know when I've found a flag?

You can consider a flag as ***anything*** that's wrapped in a pair of curly parentheses, like this: `{I_am_a_flag}`. You might not even need to do any decoding to find some of them! There are 5 flags in total of varying difficulty.

Don't forget you can run the binary! I just don't recommend reading the source if you want this to be somewhat challenging.




