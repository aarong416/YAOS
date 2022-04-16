#include <cstdlib/cstdlib.h>
#include <cstring/cstring.h>

char itoa(int value, char* s, int base)
{
    std::uint32_t i = 0;
    
    if (value == 0) {
        s[i++] = 0;

        return (int) s;
    }
    
    if (value < 0 && base == 10) {
        value = -value;
    }
    
    while (value != 0) {
        int rem = value % base;
        
        s[i++] = (rem > 9) ? (rem-10) + 'a' : rem + '0';
        
        value /= base;
    }
    
    s[i] = '\0';
    
    strrev(s);
    
    return (int) s;
}
