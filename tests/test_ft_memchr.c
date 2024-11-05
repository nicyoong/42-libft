#include <stdio.h>
#include <string.h>
#include <assert.h>

// Function prototype for ft_memchr
void *ft_memchr(const void *s, int c, size_t n);

// Test function for ft_memchr
void test_ft_memchr() {
    // Test 1: Character present in the middle of the string
    const char *str1 = "Hello, World!";
    char c1 = 'W';
    char *result_ft1 = ft_memchr(str1, c1, strlen(str1));
    char *result_std1 = memchr(str1, c1, strlen(str1));
    assert(result_ft1 == result_std1); // Both should point to 'W'

    // Test 2: Character present at the beginning
    char c2 = 'H';
    char *result_ft2 = ft_memchr(str1, c2, strlen(str1));
    char *result_std2 = memchr(str1, c2, strlen(str1));
    assert(result_ft2 == result_std2); // Both should point to 'H'

    // Test 3: Character present at the end
    char c3 = '!';
    char *result_ft3 = ft_memchr(str1, c3, strlen(str1));
    char *result_std3 = memchr(str1, c3, strlen(str1));
    assert(result_ft3 == result_std3); // Both should point to '!'

    // Test 4: Character not present in the string
    char c4 = 'x';
    char *result_ft4 = ft_memchr(str1, c4, strlen(str1));
    char *result_std4 = memchr(str1, c4, strlen(str1));
    assert(result_ft4 == result_std4); // Both should be NULL

    // Test 5: Searching for the null terminator
    char c5 = '\0';
    char *result_ft5 = ft_memchr(str1, c5, strlen(str1) + 1); // +1 to include null terminator
    char *result_std5 = memchr(str1, c5, strlen(str1) + 1);
    assert(result_ft5 == result_std5); // Both should point to the end of the string

    // Test 6: Empty string
    const char *str2 = "";
    char c6 = 'a';
    char *result_ft6 = ft_memchr(str2, c6, 1); // Size is 1, so should search the empty string
    char *result_std6 = memchr(str2, c6, 1);
    assert(result_ft6 == result_std6); // Both should be NULL

    // Test 7: Searching for null terminator in an empty string
    char *result_ft7 = ft_memchr(str2, c5, 1); // Should return NULL, as there's no bytes
    char *result_std7 = memchr(str2, c5, 1);
    assert(result_ft7 == result_std7); // Both should be NULL

    // Additional tests with various lengths
    const char *str3 = "abcdeabcde";
    char c8 = 'a';
    char *result_ft8 = ft_memchr(str3, c8, 5); // should find the first 'a'
    char *result_std8 = memchr(str3, c8, 5);
    assert(result_ft8 == result_std8); // Both should point to the first 'a'

    // Test with a length that excludes the character
    char *result_ft9 = ft_memchr(str3, c8, 4); // should return NULL
    char *result_std9 = memchr(str3, c8, 4);
    assert(result_ft9 == result_std9); // Both should be NULL

    printf("All tests passed!\n");
}

int main() {
    test_ft_memchr();
    return 0;
}
