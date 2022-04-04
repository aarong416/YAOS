ENTRY(start)
OUTPUT_FORMAT(elf32-i386)

SECTIONS
{
    /* Load the kernel at address 0x1000000 */
    . = 1M; 

    /* Add the multiboot section first so that the bootloader can recognize that this
       is a multiboot compliant bootloader.
       Next put the text section containing the code
     */
    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.multiboot)
        *(.text)
    }

    .rodata BLOCK(4K) : ALIGN(4K)
    {
        *(.rodata)
    }

    .data BLOCK(4K) : ALIGN(4K)
    {
        *(.data)
    }

    .bss BLOCK(4K) : ALIGN(4K)
    {
        *(COMMON)
        *(.bss)
    }

    end = .;
}
