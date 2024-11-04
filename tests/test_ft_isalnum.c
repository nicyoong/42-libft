#include <stdio.h>
#include <ctype.h>
#include "../libft.h" // Including the header for ft_isalnum

void test_ft_isalnum() {
    int test_chars[] = {'0', '9', 'A', 'Z', 'a', 'z', '@', '!', ' ', '1', 'b', '-', '5', '\t', 'm'};
    int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);
    int pass = 1;

    printf("Char | ASCII | isalnum | ft_isalnum | Match\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < num_tests; i++) {
        int std_result = isalnum(test_chars[i]) ? 1 : 0; // Normalize to 1 or 0
        int ft_result = ft_isalnum(test_chars[i]);
        int match = (std_result == ft_result);

        printf("  %c   |  %3d  |    %d     |     %d      |   %s\n",
               test_chars[i], test_chars[i], std_result, ft_result, match ? "Yes" : "No");

        if (!match) {
            pass = 0;
        }
    }

    printf("------------------------------------------------\n");
    if (pass) {
        printf("All tests passed! `ft_isalnum` matches `isalnum`.\n");
    } else {
        printf("Some tests failed. Check discrepancies above.\n");
    }
}

int main() {
    test_ft_isalnum();
    return 0;
}
