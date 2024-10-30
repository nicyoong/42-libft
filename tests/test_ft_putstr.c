#include <stdio.h>
#include <string.h>
#include <unistd.h>

void ft_putstr(char *str);

void test_ft_putstr() {
    // Create a temporary file to redirect output
    FILE *fp = fopen("output.txt", "w+");
    if (!fp) {
        perror("Failed to open output.txt");
        return;
    }

    // Redirect standard output to the temporary file
    int saved_stdout = dup(STDOUT_FILENO);
    dup2(fileno(fp), STDOUT_FILENO);

    // Test cases
    ft_putstr("Hello, World!\n");
    ft_putstr("42 is great.\n");
    ft_putstr("ft_putstr works!\n");

    // Restore the original stdout
    fflush(stdout);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
    fclose(fp);

    // Check the output
    fp = fopen("output.txt", "r");
    if (!fp) {
        perror("Failed to read output.txt");
        return;
    }

    char buffer[1024];
    size_t read_size = fread(buffer, 1, sizeof(buffer) - 1, fp);
    buffer[read_size] = '\0'; // Null-terminate the string
    fclose(fp);

    // Expected output
    const char *expected_output = "Hello, World!\n42 is great.\nft_putstr works!\n";

    // Print the captured output for visibility
    printf("Captured Output:\n%s", buffer);

    // Check if the output matches
    if (strcmp(buffer, expected_output) == 0) {
        printf("Test passed!\n");
    } else {
        printf("Test failed.\n");
        printf("Expected: %s", expected_output);
        printf("Got: %s", buffer);
    }

    // Remove the temporary output file
    remove("output.txt");
}

int main() {
    test_ft_putstr();
    return 0;
}
