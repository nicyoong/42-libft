#include <stdio.h>
#include "../includes/libft.h"

void test_ft_putchar(void)
{
    printf("Testing ft_putchar:\n");
    ft_putchar('H');
    ft_putchar('e');
    ft_putchar('l');
    ft_putchar('l');
    ft_putchar('o');
    ft_putchar(','); 
    ft_putchar(' ');
    ft_putchar('W');
    ft_putchar('o');
    ft_putchar('r');
    ft_putchar('l');
    ft_putchar('d');
    ft_putchar('!');
    ft_putchar('\n');

    ft_putchar('T');
    ft_putchar('e');
    ft_putchar('s');
    ft_putchar('t');
    ft_putchar('i');
    ft_putchar('n');
    ft_putchar('g');
    ft_putchar(' ');
    ft_putchar('1');
    ft_putchar('2');
    ft_putchar('3');
    ft_putchar('\n');

    ft_putchar('A');
    ft_putchar('B');
    ft_putchar('C');
    ft_putchar('D');
    ft_putchar('E');
    ft_putchar('\n');
}

int main(void)
{
    test_ft_putchar();
    return 0;
}
