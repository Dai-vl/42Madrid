/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:25:57 by dvidal-l          #+#    #+#             */
/*   Updated: 2024/01/31 13:25:58 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (s[start] && i < len)
	{
		ret[i] = s[start];
		++i;
		++start;
	}
	ret[i] = '\0';
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	num;

	num = 0;
	while (s[num] && s[num] != '\n')
		++num;
	if (s[num] == '\n')
		++num;
	return (num);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		i;

	i = 0;
	while (s1 && s1[i] && s1[i] != '\n')
		++i;
	if (s1[i] == '\n')
		++i;
	ret = malloc((i + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s1 && *s1 != '\n')
	{
		ret[i] = *s1;
		++i;
		++s1;
	}
	if (*s1 == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		++i;
	}
	if ((char) c == s[i])
		return ((char *) s + i);
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		sl;
	int		i;
	char	*ret;

	ret = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	sl = 0;
	while (s1[i])
		ret[sl++] = s1[i++];
	i = 0;
	while (s2[i] && s2[i] != '\n')
		ret[sl++] = s2[i++];
	if (s2[i] == '\n')
		ret[sl++] = '\n';
	ret[sl] = '\0';
	return (free(s1), ret);
}
