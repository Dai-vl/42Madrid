/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:14:03 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/12 21:17:59 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_needle(char *ret, char *aux, char *aux2)
{
	++aux;
	++aux2;
	if (*aux != *aux2 && *aux2 != '\0')
		ret = 0;
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ret;
	char	*aux;
	char	*aux2;
	size_t	i;

	i = 0;
	ret = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	while (*haystack != '\0' && ret == 0 && i < len)
	{
		if (*haystack == *needle)
		{
			ret = (char *) haystack;
			aux = (char *) haystack;
			aux2 = (char *) needle;
		}
		while (*aux == *aux2 && *aux2 != '\0' && i < len)
			copy_needle(ret, aux, aux2);
		++haystack;
		++i;
	}
	return (ret);
}
