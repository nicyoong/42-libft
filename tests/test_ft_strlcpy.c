#include <stdio.h>
#include <string.h>
#include <assert.h>

size_t ft_strlcpy(char *dest, const char *src, size_t size);

void test_ft_strlcpy() {
    char dest[20];
    const char *src = "Hello, World!";
    size_t result;

    // Test case 1: Normal case
    result = ft_strlcpy(dest, src, sizeof(dest));
    assert(result == strlen(src)); // Expect return value to be the length of src
    assert(strcmp(dest, src) == 0); // Expect dest to be equal to src
    printf("Test 1 passed: %s -> %s (length: %zu)\n", src, dest, result);

    // Test case 2: Size less than source length
    char dest2[10];
    result = ft_strlcpy(dest2, src, sizeof(dest2));
    assert(result == strlen(src)); // Return value should still be length of src
    assert(strcmp(dest2, "Hello, Wo") == 0); // Check if dest is truncated and null-terminated
    printf("Test 2 passed: %s -> %s (length: %zu)\n", src, dest2, result);

    // Test case 3: Size is zero
    result = ft_strlcpy(dest, src, 0);
    assert(result == strlen(src)); // Should return the length of src
    assert(dest[0] == '\0'); // dest should remain unchanged
    printf("Test 3 passed: %s (length: %zu) with size 0\n", src, result);

    // Test case 4: Empty source
    const char *empty_src = "";
    result = ft_strlcpy(dest, empty_src, sizeof(dest));
    assert(result == 0); // Length of empty string is 0
    assert(strcmp(dest, "") == 0); // dest should be empty
    printf("Test 4 passed: empty src -> %s (length: %zu)\n", dest, result);

    // Test case 5: Source longer than dest size
    const char *long_src = "This string is definitely longer than the destination buffer.";
    result = ft_strlcpy(dest, long_src, sizeof(dest));
    assert(result == strlen(long_src)); // Return value should be length of long_src
    assert(strcmp(dest, "This string ") == 0); // Check that it copied only part of the string
    printf("Test 5 passed: long src -> %s (length: %zu)\n", dest, result);

    // Test case 6: dest is the same as src
    char *same_dest = dest; // Point dest to itself
    result = ft_strlcpy(same_dest, src, sizeof(dest));
    assert(result == strlen(src)); // Expect the length of src
    assert(strcmp(dest, src) == 0); // They should be equal
    printf("Test 6 passed: same dest/src -> %s (length: %zu)\n", dest, result);

    printf("All tests passed!\n");
}

int main() {
    test_ft_strlcpy();
    return 0;
}
