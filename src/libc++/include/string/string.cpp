#include <cmath/cmath.h>
#include <cstdlib/cstdlib.h>
#include <cstring/cstring.h>
#include <iostream/iostream.h>

/**
 * Constructors
 */

// Creates a new string and sets its size to 0
std::String::String()
{
  std::cout << "Constructor 1";

  m_length = 0;
  m_capacity = BUFFER_SIZE;
  m_string = new char[BUFFER_SIZE];
  m_string[0] = '\0';
}

std::String::String(const std::string& str)
{
  std::cout << "Constructor 2";

  this->operator=(str);
}

// Creates a new string and allocates memory for it.
std::String::String(const char* s)
{
  // Allocate memory for the new string.
  // strlen(s) + 1 accounts for the extra NULL byte at the end of the string.
  // `capacity` will always be >= strlen(s)
  // `capacity` takes the null byte into account
  uint32_t capacity = (strlen(s) + 1) <= BUFFER_SIZE
                        ? BUFFER_SIZE
                        : ceil((strlen(s) + 1) / BUFFER_SIZE) * BUFFER_SIZE;

  m_string = new char[capacity];
  m_capacity = capacity;

  // No string was provided, so set its length to 0
  if (!s) {
    m_length = 0;
  } else {
    // Creates a new char array to hold the string, adds the null byte to the end of the array,
    // and sets the length of the string
    m_length = strlen(s);

    strcpy(m_string, s);

    m_string[m_length] = '\0';
  }

  std::cout << c_str() << "\n\n";
}

std::String::String(size_t n, char c)
{
  if (n == 0) {
    m_length = 0;
    m_capacity = BUFFER_SIZE;
    m_string = new char[BUFFER_SIZE];
    m_string[0] = '\0';

    return;
  }

  // `capacity` will always be >= `n`
  // `capacity` takes the null byte into account
  uint32_t capacity =
    (n + 1) <= BUFFER_SIZE ? BUFFER_SIZE : (ceil((n + 1) / BUFFER_SIZE)) * BUFFER_SIZE;

  m_string = new char[capacity];

  for (uint32_t i = 0; i <= n; i++) {
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
  for (uint32_t i = 0; i < strlen(s); i++) {
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
    // Replace the null byte with the new character, and then re-add
    // the null byte after the new character
    m_string[m_length] = c;
    m_string[m_length + 1] = '\0';
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
uint32_t std::String::compare(const char* s) const
{
  return strcmp(m_string, s);
}

/*
 * Compares two C++ strings
 */
uint32_t std::String::compare(std::String& str) const
{
  return compare(str.c_str());
}

/**
 * Operator overloads
 */

// Compares a C++ string with a C string to determine if they match
bool std::String::operator==(const char* s)
{
  return strcmp(m_string, s) == 0;
}

// Compares two C++ strings to determine if they match
bool std::String::operator==(const std::String& str)
{
  return strcmp(m_string, str.c_str()) == 0;
}

// Compares a C++ string with a C string to determine if they don't match
bool std::String::operator!=(const char* s)
{
  return strcmp(m_string, s) != 0;
}

// Compares two C++ strings to determine if they don't match
bool std::String::operator!=(const std::String& str)
{
  return strcmp(m_string, str.c_str()) != 0;
}

// Copies the contents of the C string `s` into the current string
std::String& std::String::operator=(const char* s)
{
  // If the C string is longer than the capacity of the current string,
  // calculate the new capacity based on the C string and allocated
  // a new area of memory for the string
  if (strlen(s) + 1 > m_capacity) {
    delete[] m_string;

    uint32_t capacity = (strlen(s) + 1) <= BUFFER_SIZE
                          ? BUFFER_SIZE
                          : ceil((strlen(s) + 1) / BUFFER_SIZE) * BUFFER_SIZE;
    m_string = new char[capacity];
    m_capacity = capacity;
  }

  strncpy(m_string, s, strlen(s));

  m_length = strlen(s);
  m_string[m_length] = '\0';

  return *this;
}

// Copies the contents of the C++ string `str` into the current string
std::String& std::String::operator=(const std::String& str)
{
  // Only allocate a new position on the heap for the current string if the capacity
  // of the other string is greater than the capacity of the current string
  if (str.m_capacity > m_capacity) {
    delete[] m_string;
    m_string = new char[str.m_capacity];
  }

  strncpy(m_string, str.m_string, str.m_length);

  m_capacity = str.m_capacity;
  m_length = str.m_length;

  return *this;
}

/**
 * Destructor
 */
std::String::~String()
{
  delete[] m_string;
}