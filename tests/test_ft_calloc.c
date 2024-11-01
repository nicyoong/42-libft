#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/libft.h" // Adjust the path as needed

void test_ft_calloc() {
    int *array;
    size_t count = 5;
    size_t size = sizeof(int);
    
    // Test 1: Normal allocation
    array = (int *)ft_calloc(count, size);
    if (array == NULL) {
        printf("Test 1 failed: ft_calloc returned NULL\n");
        return;
    }
    printf("Test 1: Normal allocation of %lu ints.\n", (unsigned long)count);
    for (size_t i = 0; i < count; i++) {
        printf("array[%lu] = %d\n", (unsigned long)i, array[i]); // Should be initialized to 0
    }
    free(array); // Free the allocated memory

    // Test 2: Zero allocation (should return NULL)
    array = (int *)ft_calloc(0, size);
    if (array != NULL) {
        printf("Test 2 failed: ft_calloc(0, size) should return NULL\n");
    } else {
        printf("Test 2 passed: ft_calloc(0, size) returned NULL as expected\n");
    }

    // Test 3: Small allocation with larger count
    count = 10; // Allocate memory for 10 integers
    array = (int *)ft_calloc(count, size);
    if (array == NULL) {
        printf("Test 3 failed: ft_calloc returned NULL for count %lu\n", (unsigned long)count);
        return;
    }
    printf("Test 3: Normal allocation of %lu ints.\n", (unsigned long)count);
    for (size_t i = 0; i < count; i++) {
        printf("array[%lu] = %d\n", (unsigned long)i, array[i]); // Should be initialized to 0
    }
    free(array); // Free the allocated memory

    // Test 4: Checking for memory leaks
    count = 10;
    size = 4; // For int (4 bytes)
    array = (int *)ft_calloc(count, size);
    if (array == NULL) {
        printf("Test 4 failed: ft_calloc returned NULL\n");
        return;
    }
    for (size_t i = 0; i < count; i++) {
        array[i] = i + 1; // Initialize array for further testing
    }
    printf("Test 4: Array values before free:\n");
    for (size_t i = 0; i < count; i++) {
        printf("array[%lu] = %d\n", (unsigned long)i, array[i]);
    }
    free(array); // Free the allocated memory
}

int main() {
    test_ft_calloc();
    return 0;
}
