#include <io/io.h>
#include <setup/setup.h>

void setupHardwareCursor(uint8_t cursor_start, uint8_t cursor_end)
{
  outb(PORT_VGA_COMMAND, 0x0A);
  outb(PORT_VGA_DATA, (inb(PORT_VGA_COMMAND) & 0xC0) | cursor_start);

  outb(PORT_VGA_COMMAND, 0x0B);
  outb(PORT_VGA_DATA, (inb(PORT_VGA_DATA) & 0xE0) | cursor_end);
}
