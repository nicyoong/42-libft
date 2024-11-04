#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../libft.h"

// Test function
void test_ft_strchr() {
    const char *test_str = "Hello, World!";
    char c;
    char *result_ft;
    char *result_std;

    // Test 1: Character present in the string
    c = 'W';
    result_ft = ft_strchr(test_str, c);
    result_std = strchr(test_str, c);
    assert(result_ft == result_std); // They should point to the same location

    // Test 2: Character present at the start
    c = 'H';
    result_ft = ft_strchr(test_str, c);
    result_std = strchr(test_str, c);
    assert(result_ft == result_std);

    // Test 3: Character present at the end
    c = '!';
    result_ft = ft_strchr(test_str, c);
    result_std = strchr(test_str, c);
    assert(result_ft == result_std);

    // Test 4: Character not present
    c = 'x';
    result_ft = ft_strchr(test_str, c);
    result_std = strchr(test_str, c);
    assert(result_ft == result_std); // Both should be NULL

    // Test 5: Searching for the null terminator
    c = '\0';
    result_ft = ft_strchr(test_str, c);
    result_std = strchr(test_str, c);
    assert(result_ft == result_std); // Both should point to the end of the string

    // Test 6: Empty string
    test_str = "";
    c = 'a';
    result_ft = ft_strchr(test_str, c);
    result_std = strchr(test_str, c);
    assert(result_ft == result_std); // Both should be NULL

    // Test 7: Searching for null terminator in an empty string
    c = '\0';
    result_ft = ft_strchr(test_str, c);
    result_std = strchr(test_str, c);
    assert(result_ft == result_std); // Both should point to the end of the string

    printf("All tests passed!\n");
}

int main() {
    test_ft_strchr();
    return 0;
}
