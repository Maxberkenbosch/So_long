#include "stdlib.h"
#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len);

void	*ft_calloc(size_t count, size_t size, t_tool tool)
{
	void	*ptr;

	ptr = NULL;
	if (size == 0 || count == 0)
	{
		size = 1;
		count = 1;
	}
	ptr = malloc(count * size);
	if (!ptr)
		exit_game(tool, "Memory allocation error in calloc", 0);
	ft_memset (ptr, '\0', size);
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len > 0)
	{
		len--;
		*ptr = c;
		ptr++;
	}
	return (b);
}
