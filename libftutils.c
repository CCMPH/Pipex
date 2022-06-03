/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftutils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 09:01:08 by chartema      #+#    #+#                 */
/*   Updated: 2022/06/03 09:22:40 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <stddef.h>

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
