#include <stdio.h>
#include "../includes/libft.h"

int main() {
    char buffer[10];

    // Fill the buffer with some values
    for (int i = 0; i < 10; i++) {
        buffer[i] = 'A' + i; // Fill buffer with 'A', 'B', ..., 'J'
    }

    // Display buffer contents before bzero
    printf("Before ft_bzero: ");
    for (int i = 0; i < 10; i++) {
        printf("%c ", buffer[i]);
    }
    printf("\n");

    // Call ft_bzero to zero out the first 5 bytes
    ft_bzero(buffer, 5);

    // Display buffer contents after bzero
    printf("After ft_bzero: ");
    for (int i = 0; i < 10; i++) {
        printf("%c ", buffer[i]); // Expect first 5 bytes to be zero
    }
    printf("\n");

    return 0;
}
