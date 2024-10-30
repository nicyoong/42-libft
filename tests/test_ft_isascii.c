#include <stdio.h>
#include <ctype.h>
#include "../includes/libft.h" // Including the header for ft_isascii

void test_ft_isascii() {
    int test_chars[] = {0, 32, 65, 90, 97, 122, 127, 128, 255};
    int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);
    int pass = 1;

    printf("Char | ASCII | isascii | ft_isascii | Match\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < num_tests; i++) {
        int std_result = isascii(test_chars[i]) ? 1 : 0; // Normalize to 1 or 0
        int ft_result = ft_isascii(test_chars[i]);
        int match = (std_result == ft_result);

        printf("  %c   |  %3d  |    %d     |     %d      |   %s\n",
               test_chars[i], test_chars[i], std_result, ft_result, 
               match ? "Yes" : "No");

        if (!match) {
            pass = 0;
        }
    }

    printf("------------------------------------------------\n");
    if (pass) {
        printf("All tests passed! `ft_isascii` matches `isascii`.\n");
    } else {
        printf("Some tests failed. Check discrepancies above.\n");
    }
}

int main() {
    test_ft_isascii(); // Call the test function
    return 0;         // Indicate successful execution
}
