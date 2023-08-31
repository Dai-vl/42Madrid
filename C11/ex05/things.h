/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   things.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 04:23:32 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/31 04:23:33 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THINGS_H
# define THINGS_H

# include <unistd.h>

void	ft_putnbr(int nb);

int		ft_todec(char *str);

int		space(char *str);

int		ft_atoi(char *str);

int		ft_add(int a, int b);

int		ft_sub(int a, int b);

int		ft_div(int a, int b);

int		ft_mul(int a, int b);

int		ft_mod(int a, int b);

#endif