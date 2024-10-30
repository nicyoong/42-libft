#include <stdio.h>
#include <ctype.h>

int ft_isalpha(int c); // Your custom function

void test_ft_isalpha() {
    int test_chars[] = {'A', 'Z', 'a', 'z', 'M', 'm', '0', '9', '!', ' ', '@', '\n'};
    int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);
    int pass = 1;

    printf("Char | ASCII | isalpha | ft_isalpha | Match\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < num_tests; i++) {
        int std_result = isalpha(test_chars[i]) ? 1 : 0; // Normalize to 1 or 0
        int ft_result = ft_isalpha(test_chars[i]);
        int match = (std_result == ft_result);

        printf("  %c  |  %3d  |    %d     |     %d      |   %s\n",
               test_chars[i], test_chars[i], std_result, ft_result, match ? "Yes" : "No");

        if (!match) {
            pass = 0;
        }
    }

    printf("------------------------------------------------\n");
    if (pass) {
        printf("All tests passed! `ft_isalpha` matches `isalpha`.\n");
    } else {
        printf("Some tests failed. Check discrepancies above.\n");
    }
}

int main() {
    test_ft_isalpha();
    return 0;
}
