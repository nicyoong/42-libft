#include <stdio.h>
#include <ctype.h>
#include "../includes/libft.h"

int ft_isdigit(int c); // Function prototype for ft_isdigit

void test_ft_isdigit() {
    int test_chars[] = {'0', '1', '5', '9', 'A', 'z', '@', ' ', '!', '7', '\n', '3'};
    int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);
    int pass = 1;

    printf("Char | ASCII | isdigit | ft_isdigit | Match\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < num_tests; i++) {
        int std_result = isdigit(test_chars[i]) ? 1 : 0; // Normalize to 1 or 0
        int ft_result = ft_isdigit(test_chars[i]);
        int match = (std_result == ft_result);

        printf("  %c   |  %3d  |    %d     |     %d      |   %s\n",
               test_chars[i], test_chars[i], std_result, ft_result, match ? "Yes" : "No");

        if (!match) {
            pass = 0;
        }
    }

    printf("------------------------------------------------\n");
    if (pass) {
        printf("All tests passed! `ft_isdigit` matches `isdigit`.\n");
    } else {
        printf("Some tests failed. Check discrepancies above.\n");
    }
}

int main() {
    test_ft_isdigit();
    return 0;
}
