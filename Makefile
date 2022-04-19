AS := nasm
ASFLAGS := -f elf
CC := i686-elf-g++
CFLAGS := -c -m32 -ffreestanding -g -O2 -Wall -Wextra -fno-exceptions -fno-rtti \
					-O0\
					-Wno-error=deprecated-copy \
					-Wno-error=sized-deallocation \
					-Wno-error=deprecated-copy \
					-I src/include \
					-I src/kernel  \
					-I src/libc++/include
LINKERFLAGS := -ffreestanding -nostdlib
SRCDIR := ./src
OBJDIR := ./obj
SRCFILES := $(shell find $(SRCDIR) -name *.cpp)
OBJFILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))

all: prepare assemble $(OBJFILES) link grub run

prepare:
	@clear
	@mkdir -p obj/include/io
	@mkdir -p obj/boot
	@mkdir -p obj/kernel
	@mkdir -p obj/exceptions
	@mkdir -p obj/libc++

	@echo $(OBJFILES)

assemble:
	@$(AS) $(ASFLAGS) src/boot.asm -o obj/boot/boot.o
	@$(AS) $(ASFLAGS) src/include/io/io.asm -o obj/include/io/io.o

$(OBJFILES): $(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	@echo Compile $<
	@$(CC) $(CFLAGS) $< -o $@

link:
	@$(CC) -T src/link.ld obj/boot/boot.o obj/include/io/io.o $(OBJFILES) -o iso/boot/kernel.bin $(LINKERFLAGS) -lgcc

grub: iso/boot/kernel.bin
	@grub-mkrescue --quiet iso -o os.iso

run:
	@qemu-system-i386 -cdrom os.iso

clean:
	rm -rf obj/*

debug:
	@qemu-system-i386 -cdrom os.iso -s -S
