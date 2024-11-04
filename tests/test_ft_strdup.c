#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test_ft_strdup() {
    printf("Original String          | ft_strdup             | strcmp Result\n");
    printf("---------------------------------------------------------------\n");

    const char *test_str1 = "Hello, World!";
    const char *test_str2 = "";
    const char *test_str3 = NULL; // To handle null pointer case
    const char *test_str4 = "This is a longer string to test ft_strdup functionality.";
    const char *test_str5 = "Special characters: !@#$%^&*()_+[]{}|;':\",.<>?/";
    const char *test_str6 = "Repeated characters: aaaaaaaa";

    char *dup1 = ft_strdup(test_str1);
    char *dup2 = ft_strdup(test_str2);
    char *dup3 = ft_strdup(test_str3); // Should handle this gracefully
    char *dup4 = ft_strdup(test_str4);
    char *dup5 = ft_strdup(test_str5);
    char *dup6 = ft_strdup(test_str6);

    printf("  %s                     | %s                    | %d\n", test_str1, dup1, strcmp(dup1, test_str1));
    printf("  (empty)                | %s                    | %d\n", dup2, strcmp(dup2, ""));
    printf("  (NULL)                 | %s                    | %s\n", dup3, dup3 ? dup3 : "NULL");
    printf("  %s                     | %s                    | %d\n", test_str4, dup4, strcmp(dup4, test_str4));
    printf("  %s                     | %s                    | %d\n", test_str5, dup5, strcmp(dup5, test_str5));
    printf("  %s                     | %s                    | %d\n", test_str6, dup6, strcmp(dup6, test_str6));

    // Free allocated memory
    free(dup1);
    free(dup2);
    free(dup3); // Ensure dup3 is only freed if ft_strdup can handle NULL
    free(dup4);
    free(dup5);
    free(dup6);
}

int main() {
    test_ft_strdup();
    return 0;
}
