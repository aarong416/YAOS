#include <cstdlib.h>
#include <cstdint.h>

extern std::uint32_t kernel_end;

struct MemoryBlock {
  bool allocated;
  std::uint32_t size;
};

// std::uint8_t* pos = (std::uint8_t*) 0;

// void* malloc(size_t size)
// {
//   if (size == 0) {
//     return (void*) NULL;
//   }

//   // TODO: check if the pos + size >= heap_size

//   if (pos == 0) {
//     pos = (std::uint8_t) kernel_end;
//   }
// }
