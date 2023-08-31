/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:50:13 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/30 13:50:15 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	translate_char(char c, t_data crs)
{
	if (c == crs.empty)
		return (1);
	if (c == crs.obs)
		return (0);
	return (-1);
}

char	translate_int(int a, t_data crs)
{
	if (a == 0)
		return (crs.obs);
	else
		return (crs.empty);
}

int	min(int e1, int e2, int e3)
{
	if (e1 <= e2 && e1 <= e3)
		return (e1);
	if (e2 <= e1 && e2 <= e3)
		return (e2);
	return (e3);
}

int	aux(char *str, int *num)
{
	while (*str >= '0' && *str <= '9')
	{
		if (num != 0)
			(*num) *= 10;
		*num = *num + (*str - '0');
		++str;
	}
	if (*str && (*str < '0' || *str > '9'))
		return (FAIL);
	return (SUCCESS);
}

int	ft_atoi(char *str)
{
	int	ret;
	int	num;

	ret = 0;
	num = 0;
	if ((*str == '+' || *str == '-') && *str != '\0')
	{
		if (*str == '-')
			return (FAIL);
		++str;
	}
	if (aux(str, &num) == FAIL)
		return (FAIL);
	return (num);
}
