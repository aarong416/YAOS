global inb
global outb

inb:
  ; push eax
  ; push edx

  mov dx, [esp+4] ; dx = port
  in al, dx

  ret

outb:
  mov al, [esp+8]
  mov dx, [esp+4]

  out dx, al

  ret
