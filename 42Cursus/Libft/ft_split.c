/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:20:19 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/20 15:48:54 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			++count;
		++i;
	}
	return (count);
}

static int	str_len(char const *str, char sep)
{
	int		size;
	char	*aux;

	aux = (char *)str;
	size = 0;
	while (*aux)
	{
		if (sep == *aux || *aux == '\0')
			break ;
		++size;
		++aux;
	}
	return (size);
}

static int	free_ret(char **ret, int index, char const *s, char c)
{
	int	i;

	ret[index] = malloc((str_len(s, c) + 1) * sizeof(char));
	if (!ret[index])
	{
		i = 0;
		while (i <= index)
			free(ret[i++]);
		free(ret);
		return (1);
	}
	return (0);
}

static char	**return_ret(char **ret, int index)
{
	ret[index] = 0;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**ret;
	int		j;
	int		index;

	index = 0;
	count = count_words(s, c);
	ret = malloc((count + 1) * sizeof(char *));
	if (!ret)
		return (0);
	while (index < count)
	{
		j = 0;
		while (*s == c && *s)
			++s;
		if (free_ret(ret, index, s, c))
			return (0);
		while (*s != c && *s)
		{
			ret[index][j++] = *s;
			++s;
		}
		ret[index++][j] = '\0';
	}
	return (return_ret(ret, index));
}
