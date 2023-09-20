/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:55:28 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/20 15:52:10 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	space(char c)
{
	return (c == ' ' || c == '\f' || c == '\r' || c == '\t'
		|| c == '\v' || c == '\n');
}

int	ft_atoi(const char *str)
{
	int		num;
	int		pos;

	pos = 1;
	num = 0;
	while (*str != '\0' && space(*str))
		++str;
	if (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			pos *= -1;
		++str;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		++str;
	}
	return (num * pos);
}
