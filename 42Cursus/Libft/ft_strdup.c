/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:11:40 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/20 15:49:09 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		i;

	i = 0;
	while (s1[i])
		++i;
	ret = malloc((i + 1) * sizeof(char));
	if (ret == 0)
		return (0);
	i = 0;
	while (*s1)
	{
		ret[i] = *s1;
		++i;
		++s1;
	}
	ret[i] = '\0';
	return (ret);
}
