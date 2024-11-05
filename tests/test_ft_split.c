#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Prototype for ft_split function
char **ft_split(char const *s, char c);

// Helper function to free the array returned by ft_split
void free_split_result(char **result) {
    if (!result) return;
    for (size_t i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
    free(result);
}

// Helper function to count the number of words in the split result
size_t split_result_count(char **result) {
    size_t count = 0;
    while (result && result[count] != NULL) {
        count++;
    }
    return count;
}

// Function to run a single test case
void run_test(const char *s, char delimiter, const char *expected[], size_t expected_count) {
    char **result = ft_split(s, delimiter);
    size_t result_count = split_result_count(result);

    assert(result_count == expected_count && "Mismatch in number of split parts");

    for (size_t i = 0; i < expected_count; i++) {
        assert(strcmp(result[i], expected[i]) == 0 && "Mismatch in split part content");
    }

    free_split_result(result);
}

void test_ft_split() {
    // Test 1: Basic split
    const char *expected1[] = {"Hello", "World"};
    run_test("Hello World", ' ', expected1, 2);

    // Test 2: Split with multiple delimiters in a row
    const char *expected2[] = {"Hello", "World"};
    run_test("Hello   World", ' ', expected2, 2);

    // Test 3: Split with delimiter at the beginning and end
    const char *expected3[] = {"Hello", "World"};
    run_test("  Hello World  ", ' ', expected3, 2);

    // Test 4: Single character input
    const char *expected4[] = {"A"};
    run_test("A", ' ', expected4, 1);

    // Test 5: Empty string input
    const char *expected5[] = {NULL};
    run_test("", ' ', expected5, 0);

    // Test 6: No delimiters in string
    const char *expected6[] = {"HelloWorld"};
    run_test("HelloWorld", ' ', expected6, 1);

    // Test 7: All characters are delimiters
    const char *expected7[] = {NULL};
    run_test("     ", ' ', expected7, 0);

    // Test 8: Complex delimiter case with punctuation
    const char *expected8[] = {"This", "is", "a", "test"};
    run_test("This,is,a,test", ',', expected8, 4);

    // Test 9: Special characters as delimiters
    const char *expected9[] = {"split", "these", "words"};
    run_test("split|these|words", '|', expected9, 3);

    // Test 10: Delimiter not in string
    const char *expected10[] = {"onetoken"};
    run_test("onetoken", ',', expected10, 1);

    // Test 11: Null input string
    run_test(NULL, ',', NULL, 0);

    // Test 12: Delimiter at both ends with multiple tokens
    const char *expected12[] = {"this", "is", "a", "test"};
    run_test("--this--is--a--test--", '-', expected12, 4);

    // Test 13: Consecutive delimiters with varied spacing
    const char *expected13[] = {"split", "this", "string"};
    run_test("split,,,this,,string", ',', expected13, 3);

    printf("All tests passed!\n");
}

int main() {
    test_ft_split();
    return 0;
}
