#include "so_long.h"

static int	ft_word_counter(char const *s, char c);

static int	ft_alloc(char **array, char *s, int a, char c);

static void	ft_free(char **array, int a);

char	**ft_split(char const *s, char c, int *words, t_tool tool)
{
	char	**array;
	int		a;

	if (!s)
		return (0);
	array = malloc ((ft_word_counter(s, c) + 1) * sizeof(char *));
	if (!array)
		exit_game(tool, "A malloc error in ft_split occured", 1);
	a = 0;
	a = ft_alloc(array, (char *)s, a, c);
	array[a] = NULL;
	*words = a;
	return (array);
}

static int	ft_alloc(char **array, char *s, int a, char c)
{
	size_t	len;
	int		i;
	int		strl;

	len = 0;
	i = 0;
	strl = ft_strlen(s);
	while (strl > i)
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i + len] != c && s[i + len])
				len++;
			array[a] = ft_substr(s, i, len);
			if (!array[a])
				ft_free(array, a);
			i += len;
			a++;
		}
		len = 0;
	}
	return (a);
}

static int	ft_word_counter(char const *s, char c)
{
	int			i;
	int			counter;
	const char	*pc;

	counter = 0;
	pc = &c;
	i = 0;
	if (!s || *s == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			counter++;
		}
		i++;
	}
	if (counter != 0 && s[0] != c)
		counter++;
	if (counter == 0 && s[i] == '\0' && s[i - 1] != c)
		counter++;
	return (counter);
}

static void	ft_free(char **array, int a)
{
	while (a > 0)
	{
		free(array[a]);
		a--;
	}
	free(array);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	if (len > ft_strlen(s) - start)
		return (ft_strdup(s + start));
	sub = malloc ((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start] && len > 0)
	{
		len--;
		sub[i++] = s[start++];
	}
	sub[i] = '\0';
	return (sub);
}
