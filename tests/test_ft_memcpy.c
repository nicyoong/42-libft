#include <stdio.h>
#include "../libft.h"

// Function prototype
void *ft_memcpy(void *dest, const void *src, size_t n);

// Helper function for printing bytes as hex
void print_bytes(const unsigned char *arr, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%02x ", arr[i]);
    }
    printf("\n");
}

void test_ft_memcpy() {
    int test_passed = 1;

    // 1. Basic Copy Test
    char src1[] = "Hello, world!";
    char dest1[20] = {0};
    ft_memcpy(dest1, src1, strlen(src1) + 1); // Copy with null terminator
    printf("Test 1 - Basic Copy Test:\n");
    printf("Expected: %s\n", src1);
    printf("Result:   %s\n", dest1);
    if (strcmp(src1, dest1) != 0) {
        printf("Test 1 failed!\n");
        test_passed = 0;
    } else {
        printf("Test 1 passed.\n");
    }

    // 2. Partial Copy Test
    char src2[] = "Partial copy";
    char dest2[20] = {0};
    ft_memcpy(dest2, src2, 7); // Copy "Partial" only
    printf("\nTest 2 - Partial Copy Test:\n");
    printf("Expected: Partial\n");
    printf("Result:   %s\n", dest2);
    if (strncmp(src2, dest2, 7) != 0) {
        printf("Test 2 failed!\n");
        test_passed = 0;
    } else {
        printf("Test 2 passed.\n");
    }

    // 3. Copying Binary Data
    unsigned char src3[] = {0x01, 0x02, 0xFF, 0x00, 0xAB};
    unsigned char dest3[5] = {0};
    ft_memcpy(dest3, src3, sizeof(src3));
    printf("\nTest 3 - Binary Data Copy Test:\n");
    printf("Expected: ");
    print_bytes(src3, sizeof(src3));
    printf("Result:   ");
    print_bytes(dest3, sizeof(dest3));
    if (memcmp(src3, dest3, sizeof(src3)) != 0) {
        printf("Test 3 failed!\n");
        test_passed = 0;
    } else {
        printf("Test 3 passed.\n");
    }

    // 4. Overlapping Memory (not safe for memcpy, just to check it does nothing unexpected)
    char overlap_src[] = "Overlap test!";
    ft_memcpy(overlap_src + 4, overlap_src, 7); // Undefined for memcpy
    printf("\nTest 4 - Overlapping Memory (behavior undefined for memcpy):\n");
    printf("Result: %s\n", overlap_src); // Just to show behavior; no pass/fail

    // 5. Zero Bytes to Copy
    char src5[] = "No bytes";
    char dest5[20] = "Unchanged";
    ft_memcpy(dest5, src5, 0); // Copy 0 bytes
    printf("\nTest 5 - Zero Bytes to Copy:\n");
    printf("Expected: Unchanged\n");
    printf("Result:   %s\n", dest5);
    if (strcmp(dest5, "Unchanged") != 0) {
        printf("Test 5 failed!\n");
        test_passed = 0;
    } else {
        printf("Test 5 passed.\n");
    }

    // Summary
    if (test_passed) {
        printf("\nAll tests passed.\n");
    } else {
        printf("\nSome tests failed.\n");
    }
}

int main() {
    test_ft_memcpy();
    return 0;
}
