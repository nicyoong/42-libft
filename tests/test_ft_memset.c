#include <stdio.h>
#include <string.h>
#include "../libft.h" // Adjust the path as needed

void test_ft_memset() {
    char buffer1[20];
    char buffer2[20];
    
    // Initialize buffer1 with 'B'
    memset(buffer1, 'B', sizeof(buffer1));
    // Use ft_memset to fill the first 10 bytes with 'A'
    ft_memset(buffer2, 'A', 10);
    
    printf("Test 1: Setting first 10 bytes to 'A'\n");
    printf("Buffer 2 after ft_memset: ");
    for (int i = 0; i < 20; i++) {
        printf("%c", buffer2[i]);
    }
    printf("\nExpected: AAAAAAAAAABBBBBBBBBB\n");
    
    // Test the case where n is larger than the buffer
    ft_memset(buffer2, 'C', 25); // Try to set more bytes than the buffer
    printf("Test 2: Attempt to set more bytes than buffer size\n");
    printf("Buffer 2 after ft_memset: ");
    for (int i = 0; i < 20; i++) {
        printf("%c", buffer2[i]);
    }
    printf("\nExpected: CCCCCCCCCCCCCCCCCCCC\n"); // This should ideally not be displayed

    // Reset the buffer for another test
    memset(buffer1, 'B', sizeof(buffer1));
    ft_memset(buffer1, 'D', 5);
    
    printf("Test 3: Setting first 5 bytes to 'D'\n");
    printf("Buffer 1 after ft_memset: ");
    for (int i = 0; i < 20; i++) {
        printf("%c", buffer1[i]);
    }
    printf("\nExpected: DDDDDBBBBBBBBBBBBBB\n");

    // Reset the buffer for another test
    memset(buffer2, 'B', sizeof(buffer2));
    ft_memset(buffer2, 'E', 0); // Setting zero bytes
    printf("Test 4: Setting zero bytes\n");
    printf("Buffer 2 after ft_memset: ");
    for (int i = 0; i < 20; i++) {
        printf("%c", buffer2[i]);
    }
    printf("\nExpected: BBBBBBBBBBBBBBBBBB\n"); // Should remain unchanged
}

int main() {
    test_ft_memset();
    return 0;
}
