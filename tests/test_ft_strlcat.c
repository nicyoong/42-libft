#include <stdio.h>
#include <string.h>
#include <assert.h>

// Assuming ft_strlcat is declared like this:
size_t ft_strlcat(char *dest, const char *src, size_t size);

void test_ft_strlcat() {
    char dest[50], expected[50];
    const char *src;
    size_t result, result_expected;

    // Test 1: Basic concatenation within buffer size
    strcpy(dest, "Hello");
    strcpy(expected, "Hello");
    src = " World";
    result = ft_strlcat(dest, src, sizeof(dest));
    result_expected = strlcat(expected, src, sizeof(expected));
    assert(result == result_expected);
    assert(strcmp(dest, expected) == 0);
    printf("Test 1 Passed: %s\n", dest);

    // Test 2: Exact buffer size to fit concatenation (dest + src + null terminator)
    strcpy(dest, "Hi");
    strcpy(expected, "Hi");
    src = " there";
    result = ft_strlcat(dest, src, 9); // Should just fit "Hi there\0"
    result_expected = strlcat(expected, src, 9);
    assert(result == result_expected);
    assert(strcmp(dest, expected) == 0);
    printf("Test 2 Passed: %s\n", dest);

    // Test 3: Not enough space in dest (truncation)
    strcpy(dest, "Hello");
    strcpy(expected, "Hello");
    src = " World";
    result = ft_strlcat(dest, src, 10); // Truncate " World" to " Worl"
    result_expected = strlcat(expected, src, 10);
    assert(result == result_expected);
    assert(strcmp(dest, expected) == 0);
    printf("Test 3 Passed: %s\n", dest);

    // Test 4: No space available in dest (size <= dest_len)
    strcpy(dest, "Hello");
    strcpy(expected, "Hello");
    src = " World";
    result = ft_strlcat(dest, src, 5); // No concatenation, size <= dest length
    result_expected = strlcat(expected, src, 5);
    assert(result == result_expected);
    assert(strcmp(dest, expected) == 0);
    printf("Test 4 Passed: %s\n", dest);

    // Test 5: Zero size (no concatenation should happen)
    strcpy(dest, "Hello");
    strcpy(expected, "Hello");
    src = " World";
    result = ft_strlcat(dest, src, 0); // Size 0, no change
    result_expected = strlcat(expected, src, 0);
    assert(result == result_expected);
    assert(strcmp(dest, expected) == 0);
    printf("Test 5 Passed: %s\n", dest);

    // Test 6: Concatenation with empty source
    strcpy(dest, "Hello");
    strcpy(expected, "Hello");
    src = "";
    result = ft_strlcat(dest, src, sizeof(dest)); // No change, src is empty
    result_expected = strlcat(expected, src, sizeof(expected));
    assert(result == result_expected);
    assert(strcmp(dest, expected) == 0);
    printf("Test 6 Passed: %s\n", dest);

    // Test 7: Concatenation with empty destination
    strcpy(dest, "");
    strcpy(expected, "");
    src = "Hello";
    result = ft_strlcat(dest, src, sizeof(dest)); // Should copy src to dest
    result_expected = strlcat(expected, src, sizeof(expected));
    assert(result == result_expected);
    assert(strcmp(dest, expected) == 0);
    printf("Test 7 Passed: %s\n", dest);

    // Test 8: Buffer size of 1 (should only null-terminate dest)
    strcpy(dest, "Initial");
    strcpy(expected, "Initial");
    src = "Data";
    result = ft_strlcat(dest, src, 1); // No room for src, just null-terminate
    result_expected = strlcat(expected, src, 1);
    assert(result == result_expected);
    assert(strcmp(dest, expected) == 0);
    printf("Test 8 Passed: %s\n", dest);

    // Test 9: Exact fit with multiple concatenations
    strcpy(dest, "abc");
    strcpy(expected, "abc");
    src = "def";
    result = ft_strlcat(dest, src, 7); // Fit "abcdef" exactly in buffer of 7
    result_expected = strlcat(expected, src, 7);
    assert(result == result_expected);
    assert(strcmp(dest, expected) == 0);
    printf("Test 9 Passed: %s\n", dest);

    printf("All tests passed!\n");
}

int main() {
    test_ft_strlcat();
    return 0;
}
