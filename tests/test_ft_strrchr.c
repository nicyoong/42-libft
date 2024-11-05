#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../libft.h"

void test_ft_strrchr() {
    const char *test_str1 = "Hello, World!";
    const char *test_str2 = "Hello, World!";
    const char *test_str3 = "Hello, World!";
    const char *test_str4 = "";
    const char *test_str5 = "a";
    
    // Test case 1: character present
    assert(ft_strrchr(test_str1, 'o') == strrchr(test_str2, 'o'));

    // Test case 2: character not present
    assert(ft_strrchr(test_str3, 'x') == strrchr(test_str3, 'x'));

    // Test case 3: character at the end
    assert(ft_strrchr(test_str1, '!') == strrchr(test_str2, '!'));

    // Test case 4: character is the null terminator
    assert(ft_strrchr(test_str1, '\0') == strrchr(test_str2, '\0'));

    // Test case 5: empty string
    assert(ft_strrchr(test_str4, 'a') == strrchr(test_str4, 'a'));

    // Test case 6: single character string
    assert(ft_strrchr(test_str5, 'a') == strrchr(test_str5, 'a'));
    assert(ft_strrchr(test_str5, 'b') == strrchr(test_str5, 'b'));

    printf("All tests passed!\n");
}

int main() {
    test_ft_strrchr();
    return 0;
}
