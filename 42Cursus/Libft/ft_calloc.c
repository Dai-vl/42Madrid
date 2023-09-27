/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:51:59 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/27 19:08:56 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (count == 0 || size == 0)
		return ((void *) malloc(0));
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ret = malloc(count * size);
	if (ret == 0)
		return (0);
	ft_memset(ret, 0, count * size);
	return (ret);
}
