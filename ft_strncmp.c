#include <stddef.h>

int ft_strncmp(const char *s1, const char *s2, size_t n) {
    while (n > 0) {
        if (*s1 != *s2) {
            return (*(unsigned char *)s1 - *(unsigned char *)s2);
        }
        if (*s1 == '\0') {
            return 0; // Both strings are equal up to this point
        }
        s1++;
        s2++;
        n--;
    }
    return 0; // All characters matched within n characters
}
