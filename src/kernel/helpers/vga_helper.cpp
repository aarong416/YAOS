#include <helpers/vga_helper.h>

unsigned int VgaHelper::GetVgaWidth()
{
    return 80; // TODO: change to read from multiboot struct from GRUB
}

unsigned int VgaHelper::GetVgaHeight()
{
    return 25; // TODO: change to read from multiboot struct from GRUB
}

int VgaHelper::MakeColor(VgaColor fg, VgaColor bg)
{
    return fg | bg << 4;
}
