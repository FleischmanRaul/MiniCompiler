a.exe < in.txt > p.asm
nasm -f win32 p.asm
g++.exe -o p.exe p.obj 