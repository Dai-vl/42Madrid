/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:45:30 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/20 15:53:35 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*or;
	char	*sr;

	or = (char *)dst;
	sr = (char *)src;
	if (or < sr)
		ft_memcpy(or, sr, len);
	else if (or > sr)
	{
		i = len;
		while (i > 0)
		{
			--i;
			or[i] = sr[i];
		}
	}
	return (dst);
}
