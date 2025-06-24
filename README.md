# Dream Heap - CTF Pwn Challenge

**Category:** Pwn  
**Difficulty:** Medium to Hard  



##  Description

You’ve stumbled upon an ancient, memory-unsafe treasure chest. It looks solid at first glance — every classic vulnerability seems patched. But deep within lies a flaw only a dreamer can reach.

The binary implements a simple memory allocator for "notes". You can add, delete, and view notes.  
Heap protections like **ASLR**, **NX**, and **Partial RELRO** are enabled.

Can you manipulate the program’s memory management to take control and retrieve the flag?



##  Mitigations:
- **ASLR**: Enabled  
- **NX**: Enabled  
- **Partial RELRO**: Enabled  
- **Canary**: Disabled  



##  Tools Allowed:
- GDB / pwndbg / gef
- pwntools
- radare2 / Ghidra / IDA Pro



##  Files:
- `dream_heap.c` (source)
- `Makefile`
- `dream_heap` (to be compiled locally)



##  Goal:
**Get the flag from the secret `get_flag()` function.**  
This function is **never called normally** and is protected behind an obscure use-after-free scenario.



##  Usage:
```bash
cd challenge
make
./dream_heap
```



##  Deliverable:
Submit the flag in the format `flag{<secret_value>}`.



Happy Hacking! 
