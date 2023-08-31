/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:47:53 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/27 17:47:54 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int		num;

	num = 0;
	while (*str != '\0')
	{
		++num;
		++str;
	}
	return (num);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*p1;
	char	*p2;

	p1 = src;
	p2 = dest;
	while (*p1 != '\0')
	{
		*p2 = *p1;
		++p2;
		++p1;
	}
	*p2 = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;

	i = 0;
	while (src[i])
		++i;
	ret = malloc((i + 1) * sizeof(char));
	i = 0;
	while (*src)
	{
		ret[i] = *src;
		++i;
		++src;
	}
	ret[i] = '\0';
	return (ret);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

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
