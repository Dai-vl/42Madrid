/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:03:43 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/20 15:50:23 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	int		i;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			ret = (char *)(s + i);
		++i;
	}
	if ((char) c == '\0')
		return ((char *)(s + i));
	return (ret);
}
