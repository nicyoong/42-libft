#include <stdio.h>
#include <string.h> // For the standard memmove to compare results
#include <stdlib.h> // For malloc
#include "../libft.h"  // Your custom header where ft_memmove is defined

void test_ft_memmove() {
    printf("Running tests for ft_memmove...\n");

    // Test 1: Simple non-overlapping copy
    char src1[] = "Hello, World!";
    char dest1[20];
    ft_memmove(dest1, src1, strlen(src1) + 1); // Including null terminator
    printf("Test 1 - Non-overlapping:\n");
    printf("Expected: %s\n", src1);
    printf("Result  : %s\n\n", dest1);

    // Test 2: Overlapping regions where dest is after src
    char src2[] = "123456789";
    ft_memmove(src2 + 2, src2, 5); // Move "12345" to start at index 2
    printf("Test 2 - Overlapping (dest after src):\n");
    printf("Expected: 121234589\n");
    printf("Result  : %s\n\n", src2);

    // Test 3: Overlapping regions where src is after dest
    char src3[] = "abcdefghij";
    ft_memmove(src3, src3 + 2, 5); // Move "cdefg" to start at index 0
    printf("Test 3 - Overlapping (src after dest):\n");
    printf("Expected: cdefghij\n");
    printf("Result  : %s\n\n", src3);


    // Test 4: Full buffer copy with no overlap
    char src4[] = "Non-overlapping copy test";
    char *dest4 = malloc(strlen(src4) + 1); // Dynamic allocation for flexibility
    if (dest4) {
        ft_memmove(dest4, src4, strlen(src4) + 1);
        printf("Test 4 - Full buffer non-overlapping copy:\n");
        printf("Expected: %s\n", src4);
        printf("Result  : %s\n\n", dest4);
        free(dest4);
    }

    // Test 5: Edge case - zero bytes to move
    char src5[] = "Nothing to change";
    char dest5[20];
    memset(dest5, '-', 20);
    ft_memmove(dest5, src5, 0); // No bytes copied
    printf("Test 5 - Zero bytes copied:\n");
    printf("Expected: --------------------\n");
    printf("Result  : %s\n\n", dest5);

    // Test 6: Self-copying a large buffer (10000 bytes)
    size_t large_size = 10000;
    char *src6 = malloc(large_size);
    if (src6) {
        memset(src6, 'A', large_size);
        ft_memmove(src6, src6, large_size); // Self copy
        printf("Test 6 - Self-copy of large buffer (10000 bytes):\n");
        printf("Expected: First 5 chars: AAAAA\n");
        printf("Result  : First 5 chars: %.5s\n\n", src6);
        free(src6);
    }

    // Test 7: Using ft_memmove to clear a section of a buffer
    char src7[] = "Clear this part out";
    // Move the part "this " to the left, clearing out the "part " section
    ft_memmove(src7 + 6, src7 + 10, 9); // Move " part out" into "this part out"
    memset(src7 + 15, 0, 3); // Null terminate after the moved section
    printf("Test 7 - Clearing part of a buffer:\n");
    printf("Expected: Clear out\n");
    printf("Result  : %s\n\n", src7);

    printf("ft_memmove tests completed.\n");
}

int main() {
    test_ft_memmove();
    return 0;
}
