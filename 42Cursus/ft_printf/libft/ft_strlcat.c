/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:53:41 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/20 15:49:35 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_size;
	size_t	dest_size;

	j = 0;
	src_size = ft_strlen(src);
	while (dst[j] != '\0')
		++j;
	if (dstsize == 0 || dstsize <= j)
		return (src_size + dstsize);
	dest_size = j;
	i = 0;
	while (src[i] != '\0' && i < dstsize - dest_size - 1)
	{
		dst[j] = src[i];
		++j;
		++i;
	}
	dst[j] = '\0';
	return (src_size + dest_size);
}
