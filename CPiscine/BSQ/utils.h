/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:50:12 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/29 16:14:14 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define FAIL -1
# define SUCCESS 0
# define MAX_INT_SIZE 10
# define IN_LINE_SIZE 20

typedef struct s_data
{
	int		lines;
	int		cols;
	char	empty;
	char	obs;
	char	full;
}	t_data;

typedef struct s_max
{
	int	x;
	int	y;
	int	size;
}	t_max;

void	solve(char	**map, t_data crs);

int		min(int e1, int e2, int e3);

int		aux(char *str, int *num);

int		ft_atoi(char *str);

char	*ft_strdup(char *src);

char	*ft_realloc(char *arr, int *curr_size);

int		val_symbol(char c, t_data crs);

void	ft_putstr(char *str);

int		translate_char(char c, t_data crs);

char	translate_int(int a, t_data crs);

void	free_map(char **map, t_data crs, int **dp, int mode);

void	store_chars(t_data *crs, char *line, int i);

char	*free_arr(char *arr);

int		ft_strcmp(char *s1, char *s2);

#endif
