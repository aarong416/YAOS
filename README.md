# YAOS

Yet Another Operating System

## Getting Started

1. `apt install nasm g++ xorisso qemu-system-i386`
2. `make`

## Building a Cross Compiler

To compile XOS, a cross compiler is needed (see [Why cross compiler are necessary](https://wiki.osdev.org/GCC_Cross-Compiler#Why_cross-compilers_are_necessary)). The complete article can be found on [osdev.org](https://wiki.osdev.org/GCC_Cross-Compiler).

Alternatively, you can view a list of pre-built cross compilers at [https://wiki.osdev.org/GCC_Cross-Compiler#Prebuilt_Toolchains](https://wiki.osdev.org/GCC_Cross-Compiler#Prebuilt_Toolchains) (not tested).

### Preparation

```bash
sudo apt install bison make texinfo libgmp3-dev libmpfr-dev libmpc-dev 

mkdir -p $HOME/opt/cross/{bin,build,src}

export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH" # (or add this to your `.bashrc` file)

cd $HOME/opt/cross
```

### Building Binutils

Binutils can be downloaded at [https://ftp.gnu.org/gnu/binutils/binutils-2.39.tar.gz](https://ftp.gnu.org/gnu/binutils/binutils-2.39.tar.gz), or you can browser all available versions at [https://ftp.gnu.org/gnu/binutils](https://ftp.gnu.org/gnu/binutils).

The below commands compile binutils (assembler, disassembler, and various other useful stuff), handling code in the format specified by `$TARGET`.

```bash
tar xf /path/to/binutils-src.tar.gz -C $PREFIX/src

mkdir -p $PREFIX/build/binutils-2.39
cd $PREFIX/build/gcc-2.39

$PREFIX/src/binutils-2.39/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install
```

The above process will take about 2 - 3 minutes

### Building GCC

GCC can be downloaded at [https://ftp.gnu.org/gnu/gcc/gcc-9.4.0/gcc-9.4.0.tar.gz](https://ftp.gnu.org/gnu/gcc/gcc-9.4.0/gcc-9.4.0.tar.gz), or you can browser all available versions at [https://ftp.gnu.org/gnu/gcc/](https://ftp.gnu.org/gnu/gcc/).

```bash
tar xf /path/to/binutils-src.tar.gz -C $PREFIX/src

mkdir -p $PREFIX/build/gcc-9.4.0
cd $PREFIX/build/gcc-9.4.0
 
# The $PREFIX/bin dir must be in PATH. We did that above.
which -- $TARGET-as || echo $TARGET-as is not in PATH

$PREFIX/src/gcc-4.9.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc
```

The above process will take about 20 - 25 minutes

To be able to use the newly compiled gcc globally, add `export PATH=$PATH:/home/<username>/opt/cross/bin` to your `.bashrc` file.
