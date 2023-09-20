/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:51:59 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/20 15:52:14 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (count == 0 && size == 0)
		return (malloc(1));
	if (count == 0)
		return (0);
	ret = malloc(count * size);
	if (ret == 0)
		return (ret);
	ft_memset(ret, 0, count * size);
	return (ret);
}
