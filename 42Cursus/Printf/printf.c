/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:35:47 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/29 17:59:16 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	apply_op(const char c, ...)
{

}

static void	read_format(char const *format, va_list args)
{
	int		start;
	size_t	len;
	int		i;

	i = 0;
	start = 0;
	len = 0;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			++len;
			++i;		
		}
		ft_putstr_fd(ft_substr(format, start, len), 1);
		//apply_op(format[i], ...);
		start = len;
		len = 0;
	}
}

int ft_printf(char const *format, ...)
{
	va_list	args;

	va_start(args, format);


	

}

int main()
{
	ft_printf("hola que tal", 1, 2, 3, 4);
	return 0;
}