#include <stdio.h>
#include <string.h>
#include <unistd.h>

void ft_putnbr(int n);

void test_ft_putnbr() {
    FILE *fp = fopen("output.txt", "w+");
    if (!fp) {
        perror("Failed to open output.txt");
        return;
    }

    int saved_stdout = dup(STDOUT_FILENO);
    dup2(fileno(fp), STDOUT_FILENO);

    // Test cases with newlines
    ft_putnbr(42);
    write(1, "\n", 1);  // Newline after the output
    ft_putnbr(-42);
    write(1, "\n", 1);  // Newline after the output
    ft_putnbr(0);
    write(1, "\n", 1);  // Newline after the output
    ft_putnbr(2147483647);
    write(1, "\n", 1);  // Newline after the output
    ft_putnbr(-2147483648);
    write(1, "\n", 1);  // Newline after the output

    fflush(stdout);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
    fclose(fp);

    fp = fopen("output.txt", "r");
    if (!fp) {
        perror("Failed to read output.txt");
        return;
    }

    char buffer[1024];
    size_t read_size = fread(buffer, 1, sizeof(buffer) - 1, fp);
    buffer[read_size] = '\0';

    fclose(fp);

    // Expected output for the test cases with newlines
    const char *expected_output = "42\n-42\n0\n2147483647\n-2147483648\n";

    // Print the captured output for visibility
    printf("Captured Output:\n%s", buffer);

    // Check if the output matches
    if (strcmp(buffer, expected_output) == 0) {
        printf("Test passed!\n");
    } else {
        printf("Test failed.\n");
        printf("Expected: %s\n", expected_output);
        printf("Got: %s\n", buffer);
    }

    remove("output.txt");
}

int main() {
    test_ft_putnbr();
    return 0;
}
