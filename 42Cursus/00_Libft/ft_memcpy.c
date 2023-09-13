/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:32:59 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/13 20:53:49 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	void	*or;

	if (!dst && !src)
		return (0);
	or = dst;
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *) src)[i];
		++i;
	}
	return (or);
}
