#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*pptr;

	ptr = malloc ((ft_strlen(s) * sizeof(char) + 1));
	pptr = ptr;
	if (!ptr)
		return (NULL);
	while (*s)
	{
		*ptr = *s;
		ptr++;
		s++;
	}
	*ptr = '\0';
	return (pptr);
}
