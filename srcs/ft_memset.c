#include <string.h>

void *ft_memset(void *s, int c, size_t n) {
    unsigned char *ptr = s;
    unsigned char value = (unsigned char)c;

    while (n--) {
        *ptr++ = value;
    }

    return s;
}
