#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../libft.h"

// Update to take unsigned int index as the first parameter
void to_upper(unsigned int index, char *c) {
    (void)index;  // Mark index as unused
    *c = (char)toupper((unsigned char)*c);
}

void add_index(unsigned int index, char *c) {
    // Use index in this function
    *c = *c + (char)index; // Modify character by adding its index
}

void reverse_characters(unsigned int index, char *c) {
    (void)index;  // Mark index as unused
    *c = 'z' - (*c - 'a'); // Example transformation for lowercase letters
}

void ft_striteri_test() {
    // Test Case 1: Convert string to uppercase
    char str1[] = "hello";
    ft_striteri(str1, to_upper);
    printf("Test Case 1 - Expected: HELLO, Got: %s\n", str1);

    // Test Case 2: Add index value to each character
    char str2[] = "abc"; // Expected: "ace"
    ft_striteri(str2, add_index);
    printf("Test Case 2 - Expected: ace, Got: %s\n", str2);

    // Test Case 3: Reverse characters (a -> z, b -> y, etc.)
    char str3[] = "abc"; // Expected: "zyx"
    ft_striteri(str3, reverse_characters);
    printf("Test Case 3 - Expected: zyx, Got: %s\n", str3);

    // Test Case 4: Empty string (should remain empty)
    char str4[] = ""; // Expected: ""
    ft_striteri(str4, to_upper);
    printf("Test Case 4 - Expected: , Got: %s\n", str4);

    // Test Case 5: Single character string
    char str5[] = "a"; // Expected: A
    ft_striteri(str5, to_upper);
    printf("Test Case 5 - Expected: A, Got: %s\n", str5);

    // Test Case 6: Non-alphabetic characters should remain unchanged
    char str6[] = "abc!@#"; // Expected: ABC!@#
    ft_striteri(str6, to_upper);
    printf("Test Case 6 - Expected: ABC!@#, Got: %s\n", str6);
}

int main() {
    ft_striteri_test();
    return 0;
}
 