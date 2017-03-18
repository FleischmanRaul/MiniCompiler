section .data
    dformat db "%d", 0
    newline: db "",10,0
    
section .text
    global print_int, scan_int, print_str
    extern _printf, _scanf,

print_int:  ;params: int (4 byte)
    enter 0, 0
    pusha
    pushf
    push dword [ebp+8]
    push dformat
    call _printf
    add esp, 8
    popf
    popa
    leave
    ret

scan_int:   ;params: adr int
    enter 0, 0
    pusha
    pushf
    push dword [ebp+8]
    push dformat
    call _scanf
    add esp, 8
    popf
    popa
    leave
    ret
    
print_newline:
    enter 0, 0
    pusha
    pushf
    push dword [ebp+8]
    push newline
    call _printf
    add esp, 8
    popf
    popa
    leave
    ret
