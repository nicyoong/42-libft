#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../libft.h"

// Test function for ft_strnstr
void test_ft_strnstr() {
    // Test 1: Needle is found in haystack
    const char *haystack1 = "Hello, World!";
    const char *needle1 = "World";
    char *result1 = ft_strnstr(haystack1, needle1, 13);
    char *result_std1 = strnstr(haystack1, needle1, 13);
    assert(result1 == result_std1); // Both should point to "World!"

    // Test 2: Needle is not found
    const char *haystack2 = "Hello, World!";
    const char *needle2 = "Earth";
    char *result2 = ft_strnstr(haystack2, needle2, 13);
    char *result_std2 = strnstr(haystack2, needle2, 13);
    assert(result2 == result_std2); // Both should be NULL

    // Test 3: Needle is at the start
    const char *haystack3 = "Hello, World!";
    const char *needle3 = "Hello";
    char *result3 = ft_strnstr(haystack3, needle3, 13);
    char *result_std3 = strnstr(haystack3, needle3, 13);
    assert(result3 == result_std3); // Both should point to "Hello, World!"

    // Test 4: Needle is empty
    const char *haystack4 = "Hello, World!";
    const char *needle4 = "";
    char *result4 = ft_strnstr(haystack4, needle4, 13);
    char *result_std4 = strnstr(haystack4, needle4, 13);
    assert(result4 == result_std4); // Both should point to the start of haystack

    // Test 5: Haystack is empty
    const char *haystack5 = "";
    const char *needle5 = "Hello";
    char *result5 = ft_strnstr(haystack5, needle5, 0);
    char *result_std5 = strnstr(haystack5, needle5, 0);
    assert(result5 == result_std5); // Both should be NULL

    // Test 6: Needle longer than remaining haystack
    const char *haystack6 = "Hi!";
    const char *needle6 = "Hello";
    char *result6 = ft_strnstr(haystack6, needle6, 3);
    char *result_std6 = strnstr(haystack6, needle6, 3);
    assert(result6 == result_std6); // Both should be NULL

    // Test 7: Exact match of needle length in haystack
    const char *haystack7 = "Goodbye!";
    const char *needle7 = "Goodbye!";
    char *result7 = ft_strnstr(haystack7, needle7, 8);
    char *result_std7 = strnstr(haystack7, needle7, 8);
    assert(result7 == result_std7); // Both should point to "Goodbye!"

    printf("All tests passed!\n");
}

int main() {
    test_ft_strnstr();
    return 0;
}
