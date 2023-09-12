/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:51:59 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/12 20:02:25 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t count, size_t size)
{
	void	*ret;

	if (count == 0)
		return (0);
	ret = malloc(count * size);
	if (ret == 0)
		return (ret);
	ft_bzero(ret, count * size);
	return (ret);
}
