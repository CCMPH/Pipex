/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftutils2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 09:00:22 by chartema      #+#    #+#                 */
/*   Updated: 2022/06/03 09:22:47 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (unsigned char)c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}

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
