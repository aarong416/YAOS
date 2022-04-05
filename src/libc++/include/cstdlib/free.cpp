#include <cstdlib/cstdlib.h>

void std::free(void* ptr)
{
  MemoryNode* node = (MemoryNode*) ptr;

  // If the allocated bit is set, unset it
  if (node->allocated) {
    node->allocated = false;
  }
}
