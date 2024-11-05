#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

void test_ft_strtrim() {
    char *result;

    // Test case 1: Regular trimming (leading and trailing spaces)
    result = ft_strtrim("   Hello, World!   ", " ");
    assert(result != NULL);
    assert(strcmp(result, "Hello, World!") == 0);
    free(result);

    // Test case 2: Trimming from both ends
    result = ft_strtrim("xxxHello, World!xxx", "x");
    assert(result != NULL);
    assert(strcmp(result, "Hello, World!") == 0);
    free(result);

    // Test case 3: Entirely trimmed (returns empty string)
    result = ft_strtrim("xxxx", "x");
    assert(result != NULL);
    assert(strcmp(result, "") == 0); // This should pass now
    free(result);

    // Test case 4: NULL s1 input
    result = ft_strtrim(NULL, "x");
    assert(result == NULL);

    // Test case 5: NULL set input (should return a copy of s1)
    result = ft_strtrim("   Hello   ", NULL);
    assert(result != NULL);
    assert(strcmp(result, "   Hello   ") == 0);
    free(result);

    // Test case 6: Only spaces, trim spaces
    result = ft_strtrim("      ", " ");
    assert(result != NULL);
    assert(strcmp(result, "") == 0); // This should pass now
    free(result);

    // Test case 7: Trimming characters not in the string
    result = ft_strtrim("Hello, World!", "xyz");
    assert(result != NULL);
    assert(strcmp(result, "Hello, World!") == 0);
    free(result);

    printf("All tests passed!\n");
}

int main() {
    test_ft_strtrim();
    return 0;
}
