/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:43:13 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/12 19:14:19 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*s1 != '\0' && *s2 != '\0' && i < n)
	{
		if (*s1 > *s2)
			return (1);
		if (*s2 > *s1)
			return (-1);
		++s1;
		++s2;
		++i;
	}
	if (*s1 != '\0' && i < n)
		return (1);
	else if (*s2 != '\0' && i < n)
		return (-1);
	return (0);
}
