#include "../includes/libft.h"
#include <stdio.h>
#include <ctype.h> // Include this header for isprint function
#include <stddef.h> // Include for size_t

void test_ft_isprint() {
    printf("Char | ASCII | isprint | ft_isprint | Match\n");
    printf("------------------------------------------------\n");

    char test_chars[] = { ' ', '!', '"', '#', '$', '%', '&', '\'', '(', 
                          ')', '*', '+', ',', '-', '.', '/', '0', '1', 
                          '2', '3', '4', '5', '6', '7', '8', '9', ':', 
                          ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 
                          'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 
                          'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 
                          'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', 
                          '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
                          'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 
                          'z', '{', '|', '}', '~', 127 }; // includes non-printable

    // Change 'int' to 'size_t' for the loop variable
    for (size_t i = 0; i < sizeof(test_chars); i++) {
        char c = test_chars[i];
        int ascii_val = (int)c;

        // Standardize expected value to 1 for printable characters and 0 for others
        int expected = (ascii_val >= 32 && ascii_val <= 126) ? 1 : 0;

        int result = ft_isprint(ascii_val);
        const char *match = (expected == result) ? "Yes" : "No";

        printf("  %c  |   %3d  |    %d     |     %d      |   %s\n", 
               c, ascii_val, expected, result, match);
    }
}

int main() {
    test_ft_isprint();
    return 0;
}
