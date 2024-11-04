#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test_ft_strdup() {
    printf("Original String | ft_strdup | strcmp Result\n");
    printf("--------------------------------------------------\n");

    const char *test_str1 = "Hello, World!";
    const char *test_str2 = "";
    const char *test_str3 = NULL; // To handle null pointer case

    char *dup1 = ft_strdup(test_str1);
    char *dup2 = ft_strdup(test_str2);
    char *dup3 = ft_strdup(test_str3); // Should handle this gracefully

    printf("  %s            | %s       | %d\n", test_str1, dup1, strcmp(dup1, test_str1));
    printf("  (empty)       | %s       | %d\n", dup2, strcmp(dup2, ""));
    printf("  (NULL)        | %s       | %s\n", dup3, dup3 ? dup3 : "NULL");

    // Free allocated memory
    free(dup1);
    free(dup2);
    free(dup3);
}

int main() {
    test_ft_strdup();
    return 0;
}
