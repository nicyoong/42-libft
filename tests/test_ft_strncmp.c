#include <stdio.h>
#include <string.h>
#include <assert.h>

// Custom strncmp function to be tested
int ft_strncmp(const char *s1, const char *s2, size_t n);

// Test function for ft_strncmp
void test_ft_strncmp() {
    const char *s1;
    const char *s2;
    size_t n;
    int result_ft;
    int result_std;

    // Test 1: Basic equality
    s1 = "Hello";
    s2 = "Hello";
    n = 5;
    result_ft = ft_strncmp(s1, s2, n);
    result_std = strncmp(s1, s2, n);
    assert(result_ft == result_std);
    printf("Test 1 passed.\n");

    // Test 2: s1 < s2 within first n characters
    s1 = "Apple";
    s2 = "Applf";
    n = 5;
    result_ft = ft_strncmp(s1, s2, n);
    result_std = strncmp(s1, s2, n);
    assert(result_ft == result_std);
    printf("Test 2 passed.\n");

    // Test 3: s1 > s2 within first n characters
    s1 = "Bananab";
    s2 = "Bananaa";
    n = 7;
    result_ft = ft_strncmp(s1, s2, n);
    result_std = strncmp(s1, s2, n);
    assert(result_ft == result_std);
    printf("Test 3 passed.\n");

    // Test 4: n is less than the length of both strings, should only compare first n characters
    s1 = "abcdef";
    s2 = "abcxyz";
    n = 3;
    result_ft = ft_strncmp(s1, s2, n);
    result_std = strncmp(s1, s2, n);
    assert(result_ft == result_std);
    printf("Test 4 passed.\n");

    // Test 5: n is greater than both string lengths
    s1 = "short";
    s2 = "short";
    n = 10;
    result_ft = ft_strncmp(s1, s2, n);
    result_std = strncmp(s1, s2, n);
    assert(result_ft == result_std);
    printf("Test 5 passed.\n");

    // Test 6: Comparing with an empty string
    s1 = "Hello";
    s2 = "";
    n = 5;
    result_ft = ft_strncmp(s1, s2, n);
    result_std = strncmp(s1, s2, n);
    assert(result_ft == result_std);
    printf("Test 6 passed.\n");

    // Test 7: Both strings are empty
    s1 = "";
    s2 = "";
    n = 5;
    result_ft = ft_strncmp(s1, s2, n);
    result_std = strncmp(s1, s2, n);
    assert(result_ft == result_std);
    printf("Test 7 passed.\n");

    // Test 8: Non-printable characters
    s1 = "abc\001def";
    s2 = "abc\002def";
    n = 5;
    result_ft = ft_strncmp(s1, s2, n);
    result_std = strncmp(s1, s2, n);
    assert(result_ft == result_std);
    printf("Test 8 passed.\n");

    // Test 9: Case where n is zero, should return 0
    s1 = "Hello";
    s2 = "World";
    n = 0;
    result_ft = ft_strncmp(s1, s2, n);
    result_std = strncmp(s1, s2, n);
    assert(result_ft == result_std);
    printf("Test 9 passed.\n");

    // Test 10: Long strings with partial matching
    s1 = "A very long string that goes on and on and doesn't end.";
    s2 = "A very long string that goes on and on and is different.";
    n = 20;
    result_ft = ft_strncmp(s1, s2, n);
    result_std = strncmp(s1, s2, n);
    assert(result_ft == result_std);
    printf("Test 10 passed.\n");

    // Test 11: Null terminator encountered before n
    s1 = "Hello\0hidden";
    s2 = "Hello\0world";
    n = 11;
    result_ft = ft_strncmp(s1, s2, n);
    result_std = strncmp(s1, s2, n);
    assert(result_ft == result_std);
    printf("Test 11 passed.\n");

    printf("All tests passed!\n");
}

int main() {
    test_ft_strncmp();
    return 0;
}
