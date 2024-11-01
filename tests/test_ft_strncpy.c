#include "../includes/libft.h"
#include <stdio.h>
#include <string.h>

void test_ft_strncpy() {
    printf("Source String | ft_strncpy | strcmp Result\n");
    printf("---------------------------------------------------\n");

    const char *test_str1 = "Hello, World!";
    char dest1[50];
    char dest2[50];

    strncpy(dest1, test_str1, 5);
    char *result1 = ft_strncpy(dest2, test_str1, 5);
    dest1[5] = '\0';  // Ensure dest1 is null-terminated for comparison
    printf("  %s           | %s        | %d\n", test_str1, result1, strcmp(dest1, dest2));

    const char *test_str2 = "Short";
    strncpy(dest1, test_str2, 10); // Trying to copy more than available
    char *result2 = ft_strncpy(dest2, test_str2, 10);
    printf("  %s           | %s        | %d\n", test_str2, result2, strcmp(dest1, dest2));
    
    const char *test_str3 = "";
    strncpy(dest1, test_str3, 5);
    char *result3 = ft_strncpy(dest2, test_str3, 5);
    printf("  (empty)      | %s        | %d\n", result3, strcmp(dest1, dest2));
}

int main() {
    test_ft_strncpy();
    return 0;
}
