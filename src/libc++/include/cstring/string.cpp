#include <cmath/cmath.h>
#include <cstdlib/cstdlib.h>
#include <cstring/cstring.h>

#include <drivers/tty_driver.h>

/**
 * Constructors
 */
std::String::String()
: m_length(0)
{}

/**
 * Creates a new string and allocates memory for it.
 */
std::String::String(const char* s)
{
  // Allocate memory for the new string.
  // strlen(s) + 1 accounts for the extra NULL byte at the end of the string.
  const unsigned int capacity = 
    (strlen(s) + 1) <= BUFFER_SIZE
    ? BUFFER_SIZE 
    : ceil((strlen(s) + 1) / BUFFER_SIZE) * BUFFER_SIZE;

  m_string = (char*) malloc(capacity);

  // No string was provided, so we create an empty array and set its length to 0
  if (!s) {
    m_length = 0;
  } else {
    // Creates a new char array to hold the string,
    // adds the null byte to the end of the array,
    // and sets the length of the string
    m_length = strlen(s);
    
    std::strncpy(m_string, s, strlen(s));

    m_string[m_length] = '\0';
  }

  m_capacity = capacity;
}

/**
 * Methods
 */

size_t std::String::length()
{
  return m_length;
} 

size_t std::String::size()
{
  return m_length;
}

char& std::String::at(size_t pos)
{
  return m_string[pos];
}

/**
 * Operator overloads
 */
char& std::String::operator[](size_t pos)
{
  TtyDriver driver;

  return at(pos);
}

/**
 * Destructor
 */
std::String::~String()
{
  delete m_string;
}
