#ifndef LIBFT_H
#define LIBFT_H

#include <string.h>

void ft_putchar(char c);
void ft_putnbr(int n);
void ft_putstr(char *str);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);
int ft_atoi(const char *str);
size_t ft_strlen(const char *str);
char *ft_strcpy(char *dest, const char *src);
char *ft_strdup(const char *s1);
char *ft_strncpy(char *dest, const char *src, size_t n);


#endif // LIBFT_H
