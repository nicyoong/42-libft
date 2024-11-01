#include <stdlib.h>

char *ft_strdup(const char *s1) {
    if (!s1) {
        return NULL; // Handle NULL input case
    }

    // Calculate the length of the string
    const char *start = s1; // Pointer to start of the original string
    while (*s1) { // While we don't reach the end of the string
        s1++;
    }

    size_t length = s1 - start; // Length of the string

    // Allocate memory for the duplicate string
    char *copy = (char *)malloc((length + 1) * sizeof(char));
    if (!copy) {
        return NULL; // Handle malloc failure
    }

    // Use pointer arithmetic to copy the string
    char *copy_start = copy; // Pointer to the start of the new string
    while (*start) { // Copy the string using pointers
        *copy_start++ = *start++;
    }
    *copy_start = '\0'; // Null terminate the copied string

    return copy;
}
