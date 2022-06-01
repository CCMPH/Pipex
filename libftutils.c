#include "pipex.h"
#include <stdlib.h> //nodig voor free
#include <stddef.h> //nodig voor size_t

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	l;
	unsigned int	i;

	if (*needle == 0)
		return ((char *)haystack);
	l = 0;
	while (haystack[l] != '\0' && l < len)
	{
		if (haystack[l] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[l + i] == needle[i]
				&& (l + i) < len)
				i++;
			if (needle[i] == '\0')
				return ((char *)&haystack[l]);
		}
		l++;
	}
	return (0);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static int	len_words(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char	**free_words(int count, char **splword)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(splword[i]);
		i++;
	}
	free(splword);
	return (NULL);
}

static char	**make_words(char const *s, char c, char **splword, int count)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (i < count)
	{
		while (*s == c && *s != '\0')
			s++;
		len = len_words(s, c);
		splword[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!splword[i])
			return (free_words(i, splword));
		j = 0;
		while (j < len)
		{
			splword[i][j] = *s;
			j++;
			s++;
		}
		splword[i][j] = '\0';
		i++;
	}
	splword[i] = 0;
	return (splword);
}

char	**ft_split(char const *s, char c)
{
	char	**splword;
	int		count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	splword = (char **)malloc(sizeof(char *) * (count + 1));
	if (!splword)
		return (NULL);
	splword = make_words(s, c, splword, count);
	return (splword);
}