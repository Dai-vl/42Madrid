/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:02:33 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/17 16:02:34 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_todec(char *str)
{
	int	num;

	num = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (num == 0)
			num = *str - '0';
		else
		{
			num *= 10;
			num += *str - '0';
		}
		++str;
	}
	return (num);
}

int	space(char *str)
{
	return (*str == ' ' || *str == '\f' || *str == '\r' || *str == '\t'
		|| *str == '\v' );
}

/*
** Receives a string str ("-1234") and returns de corresponding
** int number (-1234)
*/
int	ft_atoi(char *str)
{
	int	pos;
	int	num;

	num = 0;
	while (*str != '\0' && space(str))
		++str;
	pos = 1;
	while (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			pos = -pos;
		++str;
	}
	num = ft_todec(str);
	return (num * pos);
}

/*int main()
{
	int num = ft_atoi("---+--+1");
	printf("%d", num);
	return 0;
}*/