#include <drivers/tty_driver.h>
#include <cstring/cstring.h>

TtyDriver::TtyDriver()
{
    // Driver("TTY", "A TTY driver for writing to the screen", DriverType::TTY);

    m_width = VgaHelper::GetVgaWidth();
    m_height = VgaHelper::GetVgaHeight();
    m_terminal_color = VgaHelper::MakeColor(VgaColor::LightGray, VgaColor::Black);
    m_cursor_x = 0;
    m_cursor_y = 0;
}

int TtyDriver::GetTerminalColor()
{
    return m_terminal_color;
}

void TtyDriver::SetTerminalColor(VgaColor fg, VgaColor bg)
{
    m_terminal_color = VgaHelper::MakeColor(fg, bg);
}

void TtyDriver::WriteChar(char c)
{
    unsigned int width = VgaHelper::GetVgaWidth();
    unsigned int i = m_cursor_y * width + m_cursor_x;
    unsigned char* vidmem = (unsigned char*) 0xB8000; // extract to const??

    vidmem[i++] = c;
    m_cursor_x++;
    vidmem[i] = m_terminal_color;
    m_cursor_x++;

    if (m_cursor_x > width) {
        m_cursor_x = 0;
        m_cursor_y += 2;
    }
}

void TtyDriver::Write(const char* s)
{
    for (size_t i=0; i<strlen(s); i++) {
        WriteChar(s[i]);
    }
}

void TtyDriver::Write(std::string s)
{
    for (size_t i=0; i<s.length(); i++) {
        int rem = i % 10;
        char c = rem > 9 ? (rem - 10) + 'a' : rem + '0';

        WriteChar(s[i]);
    }
}
