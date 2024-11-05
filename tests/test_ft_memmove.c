#include <stdio.h>
#include <string.h>
#include <assert.h>

// Assuming ft_memmove is declared like this:
void *ft_memmove(void *dest, const void *src, size_t n);

void test_ft_memmove() {
    char dest[50], expected[50];

    // Test 1: Non-overlapping move within the same array
    strcpy(dest, "Hello, World!");
    strcpy(expected, "Hello, World!");
    ft_memmove(dest + 7, dest, 5);           // Moving "Hello" to "World"
    memmove(expected + 7, expected, 5);
    assert(strcmp(dest, expected) == 0);
    printf("Test 1 Passed: %s\n", dest);

    // Test 2: Overlapping regions, src before dest
    strcpy(dest, "abcdefg");
    strcpy(expected, "abcdefg");
    ft_memmove(dest + 1, dest, 5);           // Move "abcde" to start at index 1
    memmove(expected + 1, expected, 5);
    assert(strcmp(dest, expected) == 0);
    printf("Test 2 Passed: %s\n", dest);

    // Test 3: Overlapping regions, dest before src
    strcpy(dest, "abcdefghij");
    strcpy(expected, "abcdefghij");
    ft_memmove(dest, dest + 2, 5);           // Move "cdefg" to start at index 0
    memmove(expected, expected + 2, 5);
    assert(strcmp(dest, expected) == 0);
    printf("Test 3 Passed: %s\n", dest);

    // Test 4: Moving zero bytes
    strcpy(dest, "Sample text");
    strcpy(expected, "Sample text");
    ft_memmove(dest, dest + 2, 0);           // Move 0 bytes; should be unchanged
    memmove(expected, expected + 2, 0);
    assert(strcmp(dest, expected) == 0);
    printf("Test 4 Passed: %s\n", dest);

    // Test 5: Entirely overlapping move (self-copy)
    strcpy(dest, "Overlap");
    strcpy(expected, "Overlap");
    ft_memmove(dest, dest, 7);               // Self-copy
    memmove(expected, expected, 7);
    assert(strcmp(dest, expected) == 0);
    printf("Test 5 Passed: %s\n", dest);

    // Test 6: Large non-overlapping move
    strcpy(dest, "abcdefghijklmnopqrstuvwxyz");
    strcpy(expected, "abcdefghijklmnopqrstuvwxyz");
    ft_memmove(dest + 5, dest, 10);          // Move "abcdefg..." to start at index 5
    memmove(expected + 5, expected, 10);
    assert(strcmp(dest, expected) == 0);
    printf("Test 6 Passed: %s\n", dest);

    // Test 7: Clearing part of a buffer
    char src7[] = "Clear this part out";
    char src7_expected[] = "Clear this part out";
    ft_memmove(src7 + 6, src7 + 16, 5);      // Move "part" into "this part out"
    memmove(src7_expected + 6, src7_expected + 16, 5);
    memset(src7 + 10, 0, 9);                 // Null terminate at new end
    memset(src7_expected + 10, 0, 9);
    assert(strcmp(src7, src7_expected) == 0);
    printf("Test 7 Passed: %s\n", src7);

    // Test 8: Moving data between arrays
    char src8[] = "Source buffer";
    char dest8[20], expected8[20];
    strcpy(dest8, "Destination");
    strcpy(expected8, "Destination");
    ft_memmove(dest8, src8, 13);             // Move entire src8 to dest8
    memmove(expected8, src8, 13);
    assert(strcmp(dest8, expected8) == 0);
    printf("Test 8 Passed: %s\n", dest8);

    printf("All tests passed!\n");
}

int main() {
    test_ft_memmove();
    return 0;
}
