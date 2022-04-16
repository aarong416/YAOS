#ifndef TTY_DRIVER_H
#define TTY_DRIVER_H

#define VIDEO_MEMORY 0xB8000;

#include <drivers/driver.h>
#include <helpers/vga_helper.h>
#include <string/string.h>

class TtyDriver : public Driver
{
    public:
        TtyDriver();

        std::uint32_t GetTerminalColor();
        void SetTerminalColor(enum VgaColor fg, enum VgaColor bg);
        
        void ClearScreen();
        void WriteChar(const char c);
        void Write(const char* s);
        void Write(const std::string& s);

    private:
        std::uint32_t m_width;
        std::uint32_t m_height;
        std::uint32_t m_cursor_x;
        std::uint32_t m_cursor_y;
        std::uint32_t m_terminal_color;
};

#endif
