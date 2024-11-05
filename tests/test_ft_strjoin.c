#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Function prototype for ft_strjoin
char *ft_strjoin(char const *s1, char const *s2);

// Test function
void test_ft_strjoin() {
    // Test 1: Basic concatenation
    char *result1 = ft_strjoin("Hello, ", "World!");
    assert(result1 != NULL);
    assert(strcmp(result1, "Hello, World!") == 0);
    free(result1);

    // Test 2: Empty prefix
    char *result2 = ft_strjoin("", "World!");
    assert(result2 != NULL);
    assert(strcmp(result2, "World!") == 0);
    free(result2);

    // Test 3: Empty suffix
    char *result3 = ft_strjoin("Hello, ", "");
    assert(result3 != NULL);
    assert(strcmp(result3, "Hello, ") == 0);
    free(result3);

    // Test 4: Two empty strings
    char *result4 = ft_strjoin("", "");
    assert(result4 != NULL);
    assert(strcmp(result4, "") == 0);
    free(result4);

    // Test 5: Long strings
    char *result5 = ft_strjoin("Long string ", "concatenation test.");
    assert(result5 != NULL);
    assert(strcmp(result5, "Long string concatenation test.") == 0);
    free(result5);

    // Test 6: Memory allocation failure simulation
    // This is a bit tricky to test directly. Instead, you can temporarily
    // set malloc to return NULL, or mock it if using a testing framework.
    // Here we'll just assume it's not feasible to simulate in a real run.

    // If you had a custom allocator, you could inject a failure case.
    // For now, we just state that you should check the return value.

    printf("All tests passed!\n");
}

int main() {
    test_ft_strjoin();
    return 0;
}
