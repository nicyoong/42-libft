#include <stdio.h>
#include <string.h>
#include <assert.h>

// Function prototype for ft_memcmp
int ft_memcmp(const void *s1, const void *s2, size_t n);

// Test function for ft_memcmp
void test_ft_memcmp() {
    // Test 1: Equal memory blocks
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    int result_ft1 = ft_memcmp(str1, str2, strlen(str1));
    int result_std1 = memcmp(str1, str2, strlen(str1));
    assert(result_ft1 == result_std1); // Both should be 0

    // Test 2: Different memory blocks
    char str3[] = "Hello, World!";
    char str4[] = "Hello, World?";
    int result_ft2 = ft_memcmp(str3, str4, strlen(str3));
    int result_std2 = memcmp(str3, str4, strlen(str3));
    assert(result_ft2 == result_std2); // Both should be < 0

    // Test 3: Comparing with longer and shorter strings
    char str5[] = "Hello";
    char str6[] = "Hello, World!";
    int result_ft3 = ft_memcmp(str5, str6, 5);
    int result_std3 = memcmp(str5, str6, 5);
    assert(result_ft3 == result_std3); // Both should be 0

    // Test 4: Different lengths with unequal strings
    int result_ft4 = ft_memcmp(str5, str6, 6);
    int result_std4 = memcmp(str5, str6, 6);
    assert(result_ft4 == result_std4); // Both should be < 0

    // Test 5: Empty strings
    char str7[] = "";
    char str8[] = "";
    int result_ft5 = ft_memcmp(str7, str8, 0);
    int result_std5 = memcmp(str7, str8, 0);
    assert(result_ft5 == result_std5); // Both should be 0

    // Test 6: Comparing with NULL bytes
    char str9[] = "Hello\0World";
    char str10[] = "Hello World";
    int result_ft6 = ft_memcmp(str9, str10, 12);
    int result_std6 = memcmp(str9, str10, 12);
    assert(result_ft6 == result_std6); // Both should be < 0

    // Test 7: Full comparison of differing lengths
    char str11[] = "abc";
    char str12[] = "abcd";
    int result_ft7 = ft_memcmp(str11, str12, 3);
    int result_std7 = memcmp(str11, str12, 3);
    assert(result_ft7 == result_std7); // Both should be 0

    // Test 8: Different data types (integers)
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 4};
    int result_ft8 = ft_memcmp(arr1, arr2, sizeof(arr1));
    int result_std8 = memcmp(arr1, arr2, sizeof(arr1));
    assert(result_ft8 == result_std8); // Both should be < 0

    // Test 9: Overlapping regions
    char overlap1[] = "abcde";
    char overlap2[] = "abcde";
    int result_ft9 = ft_memcmp(overlap1 + 2, overlap2, 3);
    int result_std9 = memcmp(overlap1 + 2, overlap2, 3);
    assert(result_ft9 == result_std9); // Both should be 0

    // Test 10: Large blocks of memory
    char large1[1000];
    char large2[1000];
    memset(large1, 'A', 1000);
    memset(large2, 'A', 1000);
    int result_ft10 = ft_memcmp(large1, large2, 1000);
    int result_std10 = memcmp(large1, large2, 1000);
    assert(result_ft10 == result_std10); // Both should be 0

    printf("All tests passed!\n");
}

int main() {
    test_ft_memcmp();
    return 0;
}
