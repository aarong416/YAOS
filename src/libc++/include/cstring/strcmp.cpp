#include <cstring/cstring.h>
#include <cstdint.h>

int strcmp(const char* s1, const char* s2)
{
  std::uint32_t i = 0;

    if (*s1 < *s2) {
        return -1;
    } else if (*s1 > *s2) {
        return 1;
    }

    // Loop over the strings char by char and test them (don't read the null bytes)
    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
        if (*(s1 + 1) < *(s2 + 1)) {
            return -1;
        } else if (*(s1 + 1) > *(s2 + 1)) {
            return 1;
        }

        i++;

        // If we are at the end of the string and all the characters match, return 0
        if (i == strlen(s1) - 1 && i == strlen(s2) - 1) {
            return 0;
        }

        // Advance the pointers
        s1++, s2++;
    }

    // The first string/character is alphabetically less than the second string/character
    if (*s1 < *s2) {
        return -1;
    }
    // The first string/character is alphabetically greater than the second string/character
    else if (*s1 > *s2) {
        return 1;
    }
    // The first string/character is alphabetically equal to the second string/character
    else if (*s1 == *s2) {
        return 0;
    }

    return 0;
}
