int ft_atoi(const char *str) {
    int sign = 1;
    int result = 0;

    while (*str == ' ' || (*str >= 9 && *str <= 13)) {
        str++;
    }

    if (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1 : 1;
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}
