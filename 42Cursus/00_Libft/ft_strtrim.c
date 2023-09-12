/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:15:38 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/12 20:19:50 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc((ft_strlen(s1) + 1)* sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (!is_set(s1[i], set))
			ret[j++] = s1[i];
		++i;
	}
	ret[j] = '\0';
	return (ret);
}
