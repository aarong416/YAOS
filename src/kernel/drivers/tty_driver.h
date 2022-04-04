#ifndef TTY_DRIVER_H
#define TTY_DRIVER_H

// #include <drivers/driver.h>
#include <cstring/cstring.h>
#include <helpers/vga_helper.h>

class TtyDriver
{
public:
    TtyDriver();

    int GetTerminalColor();
    void SetTerminalColor(enum VgaColor fg, enum VgaColor bg);
    
    void ClearScreen();
    void WriteChar(char c);
    void Write(const char* s);
    void Write(std::string s);

private:
    unsigned int m_width;
    unsigned int m_height;
    unsigned int m_cursor_x;
    unsigned int m_cursor_y;
    unsigned int m_terminal_color;
};

#endif
