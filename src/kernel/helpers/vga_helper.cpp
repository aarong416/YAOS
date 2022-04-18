#include <helpers/vga_helper.h>

/**
 * Returns the screen width
 *
 * @returns The screen width
 */
uint32_t VgaHelper::getVgaWidth()
{
  return 80; // TODO: change to read from multiboot struct from GRUB
}

/**
 * Returns the screen height
 *
 * @returns The screen height
 */
uint32_t VgaHelper::getVgaHeight()
{
  return 25; // TODO: change to read from multiboot struct from GRUB
}

/**
 * Creates a color to be used for the text
 *
 * @returns The color to be used for the text
 */
uint8_t VgaHelper::makeColor(VgaColor text_color, VgaColor background_color)
{
  return text_color | background_color << 4;
}
