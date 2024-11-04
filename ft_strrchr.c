#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char *last_occurrence;
	char ch;

	last_occurrence = NULL;
	ch = (char)c;
	while (*s) {
		if (*s == ch)
			last_occurrence = (char *)s;
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
    if (last_occurrence != NULL)
        return last_occurrence;
    else
        return (NULL);
}
