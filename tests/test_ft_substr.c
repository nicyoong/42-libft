#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"

// Helper function to compare results and print test results
void run_test(const char *s, unsigned int start, size_t len, const char *expected) {
    char *result = ft_substr(s, start, len);
    
    if (expected == NULL) {
        assert(result == NULL); // Expect NULL for allocations that should fail
        printf("Test with start = %u, len = %zu: Passed (Expected NULL)\n", start, len);
    } else {
        assert(result != NULL); // Expect a valid string for successful allocations
        assert(strcmp(result, expected) == 0); // Compare with expected result
        printf("Test with start = %u, len = %zu: Passed (Got: \"%s\", Expected: \"%s\")\n", start, len, result, expected);
        free(result); // Free the allocated memory after test
    }
}

int main() {
    // Test 1: Normal case
    run_test("Hello, World!", 7, 5, "World");

    // Test 2: Start index at the beginning
    run_test("Hello, World!", 0, 5, "Hello");

    // Test 3: Start index at the end
    run_test("Hello, World!", 13, 5, ""); // Exceeding start index should return empty string

    // Test 4: Start index exceeds string length
    run_test("Hello, World!", 20, 5, ""); // Start index is greater than string length, should return empty string

    // Test 5: Length exceeds remaining string length
    run_test("Hello, World!", 7, 10, "World!"); // Should return "World!"

    // Test 6: Empty string input
    run_test("", 0, 5, ""); // Empty string, should return empty string

    // Test 7: NULL string input
    run_test(NULL, 0, 5, NULL); // NULL input, should return NULL

    // Test 8: Start index is zero with a long substring
    run_test("abcdef", 0, 10, "abcdef"); // Exceeding length, should return the whole string

    // Test 9: Start index is greater than zero with a zero length
    run_test("abcdef", 2, 0, ""); // Should return empty string

    // Test 10: Maximum length from a valid starting position
    run_test("1234567890", 3, 7, "4567890"); // Should return "4567890"

    printf("All tests completed!\n");
    return 0;
}
