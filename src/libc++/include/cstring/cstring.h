#ifndef CSTRING_H
#define CSTRING_H

#define NULL ((void*) 0)
#define BUFFER_SIZE 128

#include <cstdint.h>

typedef unsigned long size_t;

namespace std {
  class String
  {
    public:
      String();
      String(const char* s);
      ~String();

      size_t length();
      size_t size();
      char& at(size_t pos);
      char& back();
      char& front();
      std::String& append(const char* s);
      void push_back(char c);
      void pop_back();
      std::String& assign(const std::String& str);
      std::String& assign(const char* c);
      std::String& insert(size_t pos, const char* s);
      std::String& insert(size_t pos, std::String& str);
      std::String& erase(size_t pos = 0, size_t len = npos);
      std::String& replace(size_t pos, size_t len, const std::String& str);
      std::String& replace(size_t pos, size_t len, const char* s);

      char& operator[](size_t pos);

      static const size_t npos = -1;
    private:
      char* m_string;
      unsigned int m_length;
      unsigned int m_capacity;
  };

  typedef String string;

  void* memcpy(void* destination, void* source, size_t num);
  char* strcpy(char* destination, const char* src);
  char* strncpy(char* destination, const char* src, size_t num);
};

size_t strlen(const char* str);

#endif