#include <drivers/driver.h>
#include <drivers/tty_driver.h>
#include <cstring/cstring.h>
#include <string/string.h>

TtyDriver::TtyDriver()
: Driver("tty", "A TTY driver for writing to the screen", DriverType::Tty)
{
    // m_width = VgaHelper::GetVgaWidth();
    // m_height = VgaHelper::GetVgaHeight();
    // m_terminal_color = VgaHelper::MakeColor(VgaColor::LightGray, VgaColor::Black);
    // m_cursor_x = 0;
    // m_cursor_y = 0;
}

// std::uint32_t TtyDriver::GetTerminalColor()
// {
//     return m_terminal_color;
// }

// void TtyDriver::SetTerminalColor(VgaColor fg, VgaColor bg)
// {
//     m_terminal_color = VgaHelper::MakeColor(fg, bg);
// }

void TtyDriver::WriteChar(const char c)
{
    // The driver needs to be installed before text can be written to the screen
    // TODO: log out that the driver has not been installed
    // if (!isInstalled()) {
    //     return;
    // }

    // std::uint32_t width = VgaHelper::GetVgaWidth();
    // std::uint32_t i = m_cursor_y * width + m_cursor_x;
    // std::uint8_t* vidmem = (std::uint8_t*) VIDEO_MEMORY;

    // vidmem[i++] = c;
    // m_cursor_x++;
    
    // vidmem[i] = m_terminal_color;
    // m_cursor_x++;

    // if (m_cursor_x > width) {
    //     m_cursor_x = 0;
    //     m_cursor_y += 2;
    // }
}

void TtyDriver::Write(const char* s)
{
    // The driver needs to be installed before text can be written to the screen
    if (!isInstalled()) {
        return;
    }
    
    for (size_t i = 0; i < strlen(s); i++) {
        // WriteChar(s[i]);
    }
}

void TtyDriver::Write(const std::string& s)
{
    // The driver needs to be installed before text can be written to the screen
    if (!isInstalled()) {
        return;
    }

    for (size_t i = 0; i < s.length(); i++) {
        WriteChar(s[i]);
    }
}
