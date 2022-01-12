#include <exceptions/exception.h>

Exception::Exception(const char* message, std::uint32_t code)
: m_message(message),
  m_code(code)
{}

/**
 * Returns the exception message
 * 
 * @returns const char* The exception message
 */
const char* Exception::getMessage()
{
  return m_message;
}

/**
 * Returns the exception code
 * 
 * @returns uint32_t The exception code
 */
std::uint32_t Exception::getCode()
{
  return m_code;
}