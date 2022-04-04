#ifndef _KERNEL_H
#define _KERNEL_H

#define MAX_MEMORY_NODES 64

#include <multiboot/multiboot2.h>
#include <memory/memory.h>
#include <cstdint.h>
#include <cstddef.h>

using namespace std;

extern "C" void kernel_main();
extern std::uint32_t end;

std::uint32_t kernel_end = (std::uint32_t) &end;

#endif
