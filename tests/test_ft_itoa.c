#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

// Prototype for the function to be tested
char *ft_itoa(int n);

// Test function
void test_ft_itoa() {
    // Test case 1: Positive integer
    char *result = ft_itoa(12345);
    assert(result != NULL);
    assert(strcmp(result, "12345") == 0);
    free(result);

    // Test case 2: Negative integer
    result = ft_itoa(-12345);
    assert(result != NULL);
    assert(strcmp(result, "-12345") == 0);
    free(result);

    // Test case 3: Zero
    result = ft_itoa(0);
    assert(result != NULL);
    assert(strcmp(result, "0") == 0);
    free(result);

    // Test case 4: Minimum integer (INT_MIN)
    result = ft_itoa(INT_MIN);
    assert(result != NULL);
    assert(strcmp(result, "-2147483648") == 0);
    // No need to free as it's a static string literal

    // Test case 5: Maximum integer (INT_MAX)
    result = ft_itoa(INT_MAX);
    assert(result != NULL);
    assert(strcmp(result, "2147483647") == 0);
    free(result);

    // Test case 6: Single-digit negative number
    result = ft_itoa(-3);
    assert(result != NULL);
    assert(strcmp(result, "-3") == 0);
    free(result);

    // Test case 7: Single-digit positive number
    result = ft_itoa(7);
    assert(result != NULL);
    assert(strcmp(result, "7") == 0);
    free(result);

    // Test case 8: Negative one
    result = ft_itoa(-1);
    assert(result != NULL);
    assert(strcmp(result, "-1") == 0);
    free(result);

    // Test case 9: Negative ten
    result = ft_itoa(-10);
    assert(result != NULL);
    assert(strcmp(result, "-10") == 0);
    free(result);

    // Test case 10: Positive ten
    result = ft_itoa(10);
    assert(result != NULL);
    assert(strcmp(result, "10") == 0);
    free(result);

    // Test case 11: Positive one hundred
    result = ft_itoa(100);
    assert(result != NULL);
    assert(strcmp(result, "100") == 0);
    free(result);

    // Test case 12: Large positive number
    result = ft_itoa(123456789);
    assert(result != NULL);
    assert(strcmp(result, "123456789") == 0);
    free(result);

    // Test case 13: Large negative number
    result = ft_itoa(-123456789);
    assert(result != NULL);
    assert(strcmp(result, "-123456789") == 0);
    free(result);

    printf("All tests passed!\n");
}

// Main function to run the tests
int main() {
    test_ft_itoa();
    return 0;
}
