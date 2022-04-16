#ifndef STRING_H
#define STRING_H

#define BUFFER_SIZE 128

#include <cstddef.h>
#include <cstdint.h>

namespace std
{
  class String
  {
    public:
    String(const char* s);
    String(size_t n, char c);
    ~String();

    inline size_t length() const { return m_length; };
    inline size_t size() const { return m_length; };

    inline char& at(size_t pos) { return m_string[pos]; };
    inline const char& at(size_t pos) const { return m_string[pos]; };

    inline char& back() const { return m_string[m_length - 1]; };
    inline char& front() const { return m_string[0]; };
    std::String& append(const char* s);
    void push_back(char c);
    void pop_back();
    std::String& assign(const char* s);
    inline const char* c_str() const { return m_string; };
    std::String& assign(const std::String& str);

    // uint32_t compare(std::String& str) const;
    uint32_t compare(const char* s) const;

    std::String& insert(size_t pos, const char* s);
    std::String& insert(size_t pos, std::String& str);
    std::String& erase(size_t pos = 0, size_t len = npos);
    std::String& replace(size_t pos, size_t len, const std::String& str);
    std::String& replace(size_t pos, size_t len, const char* s);
    void reserve(size_t n = 0);
    size_t find(const std::String& str, size_t pos = 0);
    size_t find(const char* s, size_t pos = 0);

    std::String& operator=(const std::String& str);
    std::String& operator=(char c);

    std::String& operator=(const char* s);
    inline char& operator[](size_t pos) { return at(pos); };
    inline const char& operator[](size_t pos) const { return at(pos); };

    static const size_t npos = -1;

    private:
    char* m_string;
    uint32_t m_length;
    uint32_t m_capacity;
  };

  typedef String string;

  std::string to_string(int value);
} // namespace std

#endif
