#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../libft.h"

// Test function
void test_ft_strlcat() {
    char dest[50];
    const char *src;
    size_t result;

    // Test 1: Normal concatenation
    strcpy(dest, "Hello");
    src = " World";
    result = ft_strlcat(dest, src, sizeof(dest));
    assert(result == 11); // 5 + 6
    assert(strcmp(dest, "Hello World") == 0);

    // Test 2: dest is large enough to hold src
    strcpy(dest, "Hello");
    src = " World";
    result = ft_strlcat(dest, src, 20);
    assert(result == 11); // 5 + 6
    assert(strcmp(dest, "Hello World") == 0);

    // Test 3: Not enough space in dest
    strcpy(dest, "Hello");
    src = " World";
    result = ft_strlcat(dest, src, 10);
    assert(result == 11); // 5 + 6
    assert(strcmp(dest, "Hello Worl") == 0); // 'd' is not included

    // Test 4: dest is empty
    strcpy(dest, "");
    src = "World";
    result = ft_strlcat(dest, src, sizeof(dest));
    assert(result == 5); // Just "World"
    assert(strcmp(dest, "World") == 0);

    // Test 5: src is empty
    strcpy(dest, "Hello");
    src = "";
    result = ft_strlcat(dest, src, sizeof(dest));
    assert(result == 5); // No change in dest
    assert(strcmp(dest, "Hello") == 0);

    // Test 6: Both dest and src are empty
    strcpy(dest, "");
    src = "";
    result = ft_strlcat(dest, src, sizeof(dest));
    assert(result == 0); // Both are empty
    assert(strcmp(dest, "") == 0);

    // Test 7: Size is less than or equal to the length of dest
    strcpy(dest, "Hello");
    src = " World";
    result = ft_strlcat(dest, src, 5);
    assert(result == 11); // 5 + 6
    assert(strcmp(dest, "Hello") == 0); // No change since size <= dest_len

    printf("All tests passed!\n");
}

int main() {
    test_ft_strlcat();
    return 0;
}
