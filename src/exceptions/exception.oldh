#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <cstdint.h>

class Exception {
  public:
    Exception();
    Exception(const char* message, std::uint32_t code = 0);

    const char* getMessage();
    std::uint32_t getCode();
  
  protected:
    const char* m_message;
    std::uint32_t m_code;
};

#endif