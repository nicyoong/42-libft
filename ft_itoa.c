/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:58:39 by nyoong            #+#    #+#             */
/*   Updated: 2024/11/05 17:00:38 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_num_length(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length = 1;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static char	*convert_to_string(unsigned int num, int len, int is_negative)
{
	char	*str;
	int		index;

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (is_negative)
		str[0] = '-';
	index = len - 1;
	while (index >= 0)
	{
		if (index == 0 && is_negative)
			break ;
		str[index] = (num % 10) + '0';
		num /= 10;
		index--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	num;
	static char		*min_str;

	if (n == -2147483648)
	{
		min_str = "-2147483648";
		return (min_str);
	}
	len = get_num_length(n);
	if (n < 0)
		num = -n;
	else
		num = n;
	return (convert_to_string(num, len, n < 0));
}
