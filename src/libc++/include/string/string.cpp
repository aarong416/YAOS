#include <cmath/cmath.h>
#include <cstring/cstring.h>
#include <cstdlib/cstdlib.h>
#include <drivers/driver_manager.h>
#include <drivers/tty_driver.h>
#include <string/string.h>

/**
 * Constructors
 */

// Creates a new string and allocates memory for it.
std::String::String(const char* s)
{
  TtyDriver* tty = new TtyDriver();

  DriverManager::installDriver(tty);

  // tty->WriteChar('a');

  return;

  // Allocate memory for the new string.
  // strlen(s) + 1 accounts for the extra NULL byte at the end of the string.
  std::uint32_t capacity = 
    (strlen(s) + 1) <= BUFFER_SIZE
    ? BUFFER_SIZE 
    : ceil((strlen(s) + 1) / BUFFER_SIZE) * BUFFER_SIZE;

  // m_string = new char[capacity];

  m_string = (char*) malloc(capacity);

  // No string was provided, so we create an empty array and set its length to 0
  if (!s) {
    m_length = 0;
  } else {
    // Creates a new char array to hold the string,
    // adds the null byte to the end of the array,
    // and sets the length of the string
    m_length = strlen(s);
    
    strncpy(m_string, s, strlen(s));

    m_string[m_length] = '\0';
  }

  m_capacity = capacity;
}

std::String::String(size_t n, char c)
{
  TtyDriver* tty = new TtyDriver();

  DriverManager::installDriver(tty);

  tty->WriteChar('3');

  return;

  if (n == 0) {
    return;
  }

  std::uint32_t capacity = 
    n <= BUFFER_SIZE
    ? BUFFER_SIZE 
    : (ceil(n + 1) / BUFFER_SIZE) * BUFFER_SIZE;

  m_string = new char[capacity];

  for (std::uint32_t i = 0; i <= n; i++) {
    m_string[i] = c;
  }

  m_length = n;
  m_capacity = capacity;

  m_string[m_length] = '\0';
}

/**
 * Methods
 */

// Appends a string onto the end of the string
std::String& std::String::append(const char* s)
{
  for (std::uint32_t i = 0; i < strlen(s); i++) {
    push_back(s[i]);
  }

  return *this;
}

// Appends a single character onto the end of the string
void std::String::push_back(const char c)
{
  if (m_length + 1 > m_capacity) {
    // TODO: allocate more memory
    // TODO: take into account the null byte (+2 and not +1)?
  } else {
    m_string[m_length++] = c;
  }
}

// Removes the last character in the string
void std::String::pop_back()
{
  m_string[m_length - 1] = '\0';
  m_length--;
}

// Assigns a new C++ string, replacing the value of the current string
std::String& std::String::assign(const std::String& str)
{
  if (str.length() > m_capacity) {
    // TODO: allocate more memory
  } else {
    strncpy(m_string, str.c_str(), str.length());
  }

  return *this;
}

// Assigns a new C string, replacing the value of the current string
std::String& std::String::assign(const char* s)
{
  if (strlen(s) + 1 > m_capacity) {
    // TODO: allocate more memory
  } else {
    strncpy(m_string, s, strlen(s));

    m_length = strlen(s);
  }

  return *this;
}

/**
 * Compares the provided string `s` with the current string
 */
std::uint32_t std::String::compare(const char* s) const
{
  // TtyDriver* tty = (TtyDriver*) DriverManager::getDriver("tty");

  // tty->Write(strcmp(m_string, s) == -1 ? "X" : "Y");

  return strcmp(m_string, s);
}

/**
 * Operator overloads
 */

// Copies the contents of the C string `s` into the current string
std::String& std::String::operator=(const char* s)
{
  if (strlen(s) + 1 > m_capacity) {
    // TODO: allocate more memory
  } else {
    strncpy(m_string, s, strlen(s));

    m_length = strlen(s);
  }

  return *this;
}

/**
 * Destructor
 */
std::String::~String()
{
  delete[] m_string;
}
