[bits 32]

extern kernel_main

global start

; Multiboot 2 header structure:
;   - magic
;   - architecture (0 = 32 bit)
;   - header length
;   - checksum
;   - tags

MAGIC equ 0xE85250D6
ARCH equ 0
CHECKSUM equ -(MAGIC+HEADER_LEN)
TAGS equ 0
HEADER_LEN equ 10

section .multiboot

align 4
dd MAGIC
dd ARCH
dd HEADER_LEN
dd CHECKSUM
dd TAGS

section .text

start:
    mov esp, stack_space
    push ebx
    push eax

    call kernel_main
    hlt

section .bss

resb 8192

stack_space: