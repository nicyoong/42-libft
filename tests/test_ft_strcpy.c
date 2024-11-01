#include "../includes/libft.h"
#include <stdio.h>
#include <string.h>

void test_ft_strcpy() {
    printf("Original String | ft_strcpy | strcmp Result\n");
    printf("--------------------------------------------------\n");

    const char *test_str1 = "Hello, World!";
    char dest1[50];
    char dest2[50];

    strcpy(dest1, test_str1);
    char *result1 = ft_strcpy(dest2, test_str1);

    printf("  %s            | %s       | %d\n", test_str1, result1, strcmp(dest1, dest2));
    
    const char *test_str2 = "";
    strcpy(dest1, test_str2);
    char *result2 = ft_strcpy(dest2, test_str2);
    printf("  (empty)       | %s       | %d\n", result2, strcmp(dest1, dest2));
}

int main() {
    test_ft_strcpy();
    return 0;
}
