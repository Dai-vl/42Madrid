/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:48:05 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/27 17:48:06 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define FAIL -1
# define SUCCESS 0
# define INI_TAM 35
# define ERROR "Error\n"
# define DICT_ERROR "Dict Error\n"
# include <unistd.h>
# include <stdlib.h>
# include "data.h"
# include "dictionary.h"

/*
** Receives a string str and returns de corresponding
** int number
*/
int				ft_atoi(char *str, unsigned int *num);

/*
** Implementations of standar manipulation of strings
*/
void			ft_putstr(char *str);

int				ft_strlen(char *str);

char			*ft_strdup(char *src);

char			*ft_strcpy(char *dest, char *src);

int				ft_strncmp(char *s1, char *s2, unsigned int n);

int				ft_power(unsigned int nb, int power);

int				check_repeated(t_map *tab, int size);

void			sort(t_data *tab, int size);

#endif
