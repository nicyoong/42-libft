#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // For toupper and tolower
#include <string.h> // For strcmp

char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Test function to convert each character to uppercase
char to_upper(unsigned int index, char c) {
    return (char)toupper(c);
}

// Test function to convert each character to lowercase
char to_lower(unsigned int index, char c) {
    return (char)tolower(c);
}

// Function to run a single test case
void run_test(const char *test_name, char *(*func)(const char *, char (*)(unsigned int, char)), const char *input, char (*f)(unsigned int, char), const char *expected) {
    char *result = func(input, f);
    if (result == NULL) {
        printf("%s: NULL result (allocation failure)\n", test_name);
    } else if (strcmp(result, expected) == 0) {
        printf("%s: Passed\n", test_name);
    } else {
        printf("%s: Failed. Expected \"%s\", but got \"%s\"\n", test_name, expected, result);
    }
    free(result); // Free the allocated memory
}

// Main function to run tests
int main() {
    // Test cases for converting to uppercase
    run_test("Test 1 - Uppercase", ft_strmapi, "hello", to_upper, "HELLO");
    run_test("Test 2 - Uppercase with spaces", ft_strmapi, "hello world", to_upper, "HELLO WORLD");
    run_test("Test 3 - Uppercase mixed case", ft_strmapi, "HeLLo WoRLD", to_upper, "HELLO WORLD");
    run_test("Test 4 - Uppercase empty string", ft_strmapi, "", to_upper, "");
    run_test("Test 5 - Uppercase with special chars", ft_strmapi, "h3ll0!", to_upper, "H3LL0!");

    // Test cases for converting to lowercase
    run_test("Test 6 - Lowercase", ft_strmapi, "HELLO", to_lower, "hello");
    run_test("Test 7 - Lowercase with spaces", ft_strmapi, "HELLO WORLD", to_lower, "hello world");
    run_test("Test 8 - Lowercase mixed case", ft_strmapi, "HeLLo WoRLD", to_lower, "hello world");
    run_test("Test 9 - Lowercase empty string", ft_strmapi, "", to_lower, "");
    run_test("Test 10 - Lowercase with special chars", ft_strmapi, "H3LL0!", to_lower, "h3ll0!");

    // Additional tests
    run_test("Test 11 - Single character uppercase", ft_strmapi, "A", to_lower, "a");
    run_test("Test 12 - Single character lowercase", ft_strmapi, "a", to_upper, "A");
    
    return 0;
}
