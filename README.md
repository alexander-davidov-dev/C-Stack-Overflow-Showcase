# C Stack Overflow Showcase

Educational proof-of-concept demonstrating a buffer overflow vulnerability in a Windows x64 C application. This project shows how an unchecked buffer can be exploited to redirect execution flow to a hidden function.

## Project Structure
- `snowflakes.c`: The vulnerable target application (English version).
- `gen.c`: Exploit generator (calculates stack offset and injects return address).
- `demo.gif`: Visual confirmation of the attack.

## The Exploit
The application uses a vulnerable `scanf("%s", buffer)` call. We overwrite the stack with:
1. **16 bytes** of buffer padding.
2. **8 bytes** for the saved RBP.
3. **8 bytes** for the new Return Address (`0x140001450`).

## Live Demo
![Exploit Demo](demo.gif)

## Compilation (GCC)
```powershell
# Target
gcc -fno-stack-protector -no-pie -o exploit.exe snowflakes.c
# Exploit
gcc gen.c -o gen.exe && ./gen.exe
# Run
Get-Content payload.txt -Raw | ./exploit.exe
