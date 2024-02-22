/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:45:12 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/27 17:45:16 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_data
{
	unsigned int	key;
	char			*value;
	int				size;
}	t_data;

typedef struct s_map
{
	int		size;
	t_data	*map_arr;
}	t_map;
/*
** Data manipulation functions
*/
t_data			new_data(int size);

t_map			new_map(int size);

t_data			mem_resize(t_data *array);

t_map			map_resize(t_map *map);

#endif
