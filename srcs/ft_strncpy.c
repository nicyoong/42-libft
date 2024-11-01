#include "../includes/libft.h"

char *ft_strncpy(char *dest, const char *src, size_t n) {
    char *original_dest = dest;

    while (n > 0 && *src) {
        *dest++ = *src++;
        n--;
    }

    while (n > 0) {
        *dest++ = '\0';
        n--;
    }

    return original_dest;
}
