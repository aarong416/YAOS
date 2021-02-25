AS := nasm
ASFLAGS := -f elf
CC := i686-elf-g++
CFLAGS := -c -m32 -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -I src/kernel -I src/kernel/drivers
LINKERFLAGS := -ffreestanding -nostdlib
SRCDIR := ./src
OBJDIR := ./obj
SRCFILES := $(shell find $(SRCDIR) -name *.cc)
OBJFILES := $(patsubst $(SRCDIR)/%.cc,$(OBJDIR)/%.o,$(SRCFILES))

all: prepare assemble $(OBJFILES) link grub run

prepare:
	@clear
	@mkdir -p obj

assemble: obj/boot.o
	@$(AS) $(ASFLAGS) src/boot.asm -o obj/boot.o

$(OBJFILES): $(OBJDIR)/%.o: $(SRCDIR)/%.cc
	@mkdir -p $(@D)
	@echo Compile $<
	@$(CC) $(CFLAGS) $< -o $@

link:
	@$(CC) -T src/link.ld obj/boot.o $(OBJFILES) -o iso/boot/kernel.bin $(LINKERFLAGS) -lgcc

grub: iso/boot/kernel.bin
	@grub-mkrescue --quiet iso -o os.iso

run:
	@qemu-system-i386 -cdrom os.iso

clean:
	rm -rf obj
