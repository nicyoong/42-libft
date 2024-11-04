#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

void test_ft_atoi() {
    printf("Input String                | Expected | ft_atoi | Match\n");
    printf("--------------------------------------------------------\n");

    const char *test_strings[] = {
        "42",
        "-42",
        "   42",
        "+42",
        "123456",
        "   -123456   ",
        "2147483647",
        "-2147483648",
        "2147483648", // overflow
        "-2147483649", // underflow
        "abc", // non-numeric
        "  \n  \t  \r  123", // leading whitespace
        "", // empty string
        "--5", // invalid case
        "+-5", // invalid case
        NULL
    };

    for (size_t i = 0; test_strings[i] != NULL; i++) {
        int expected = atoi(test_strings[i]);
        int result = ft_atoi(test_strings[i]);
        const char *match = (expected == result) ? "Yes" : "No";
        
        printf("%-25s | %-8d | %-7d | %s\n", 
               test_strings[i] ? test_strings[i] : "NULL", expected, result, match);
    }
}

int main() {
    test_ft_atoi();
    return 0;
}
