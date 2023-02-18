gdt_start:
  ; First segment: always null
  dd 0x00
  dd 0x00

  ; kernel code descriptor
  dw 0xFFFF
  dw 0x00
  db 0x00
  db 0b10011010
  db 0b11001111
  db 0x00

  ; kernel data descriptor
  dw 0xFFFF
  dw 0x00
  db 0x00
  db 0b10010010
  db 0b11001111
  db 0x00


  ; user code descriptor
  dw 0xFFFF
  dw 0x00
  db 0x00
  db 0b11111010
  db 0b11001111
  db 0x00

  ; user data descriptor
  dw 0xFFFF
  dw 0x00
  db 0x00
  db 0b11110010
  db 0b11001111
  db 0x00

gdt_end:

gdt_descriptor:
  dw gdt_end - gdt_start - 1
  dd gdt_start

; Load the GDT
cli                   ; disable interrupts
lgdt [gdt_descriptor]
mov eax, cr0          ; enable protected mode
or eax, 0x1
mov cr0, eax

jmp 0x08:protected_mode_main

protected_mode_main:
  mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax

  ret