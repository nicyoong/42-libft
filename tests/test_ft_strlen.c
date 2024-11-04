#include <stdio.h>
#include <string.h> // For size_t
#include "../libft.h" // Replace with your actual header for ft_strlen

void test_ft_strlen() {
    printf("String | Expected Length | Actual Length | Match\n");
    printf("----------------------------------------------\n");

    const char *test_strings[] = {
        "", 
        "a", 
        "Hello", 
        "Hello, World!", 
        "Lorem ipsum dolor sit amet", 
        "1234567890", 
        "A longer string with more characters"
    };

    // Change the loop counter type to size_t
    for (unsigned int i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); i++) {
        const char *str = test_strings[i];
        size_t expected_length = strlen(str);  // Standard strlen
        size_t actual_length = ft_strlen(str);  // Your custom ft_strlen
        const char *match = (expected_length == actual_length) ? "Yes" : "No";

        printf("%s | %lu | %lu | %s\n", str, (unsigned long)expected_length, (unsigned long)actual_length, match);
    }
}

int main() {
    test_ft_strlen();
    return 0;
}
