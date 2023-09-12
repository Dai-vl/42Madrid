/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:27:25 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/12 21:16:58 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*p2;
	int		i;
	size_t	size_src;

	i = 0;
	size_src = 0;
	p2 = dst;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && size_src < dstsize - 1)
		{
			*p2 = src[i];
			++p2;
			++i;
			++size_src;
		}
	}
	*p2 = '\0';
	while (src[i] != '\0')
	{
		++size_src;
		++i;
	}
	return (size_src);
}
