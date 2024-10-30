#include "../includes/libft.h"
#include <stdio.h>

void test_ft_tolower() {
    printf("Char | ASCII | tolower | ft_tolower | Match\n");
    printf("------------------------------------------------\n");

    char test_chars[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 
                          'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
                          'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 
                          'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 
                          'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 
                          'W', 'X', 'Y', 'Z', '0', '1', '2', '3', 
                          '4', '5', '6', '7', '8', '9', '!', '@', 
                          '#', '$', '%', '^', '&', '*', '(', ')', 
                          '-', '=', '{', '}', '[', ']', ':', ';', 
                          '"', '\'', '<', '>', '?', ',', '.', '/', 
                          '`', '~', '\\', ' ' };

    for (size_t i = 0; i < sizeof(test_chars); i++) {
        char c = test_chars[i];
        int expected = (c >= 'A' && c <= 'Z') ? (c + ('a' - 'A')) : c;
        int result = ft_tolower(c);
        const char *match = (expected == result) ? "Yes" : "No";

        printf("  %c  |   %3d  |    %c     |     %c      |   %s\n", 
               c, (int)c, (char)expected, (char)result, match);
    }
}

int main() {
    test_ft_tolower();
    return 0;
}
