/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:20:19 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/12 21:31:45 by dvidal-l         ###   ########.fr       */
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
		if (str[i] != c && str[i + 1] == c)
			++count;
		++i;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**ret;
	int		j;
	int		index;

	j = 0;
	index = 0;
	count = count_words(s, c);
	ret = malloc((count + 1) * sizeof(char *));
	if (!ret)
		return (0);
	ret[index] = malloc((ft_strlen(s) + 1) * sizeof(char));
	while (index < count)
	{
		if (*s != c)
			ret[index][j++] = *s;
		else
		{
			j = 0;
			ret[++index] = malloc(ft_strlen(s) * sizeof(char));
		}
		++s;
	}
	ret[index] = 0;
	return (ret);
}
