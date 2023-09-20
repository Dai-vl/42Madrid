/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:27:25 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/20 15:49:42 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;

	i = 0;
	while (dstsize != 0 && src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		++i;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (ft_strlen(src));
}
