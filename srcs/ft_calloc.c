#include <stdlib.h>
#include <string.h>

void *ft_memset(void *s, int c, size_t n) {
    unsigned char *ptr = s;
    unsigned char value = (unsigned char)c;

    while (n--) {
        *ptr++ = value;
    }

    return s;
}

void* ft_calloc(size_t num, size_t size) {
    size_t total_size = num * size;

    void* ptr = malloc(total_size);

    if (ptr == NULL) {
        return NULL;
    }

    ft_memset(ptr, 0, total_size);

    return ptr;

}
