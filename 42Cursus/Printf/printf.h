/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:37:55 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/29 17:56:50 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>

const char	OPS = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'};

int ft_printf(char const *format, ...);

#endif