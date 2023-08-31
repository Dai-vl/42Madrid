/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:40:27 by mcarnere          #+#    #+#             */
/*   Updated: 2023/08/27 02:40:29 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_data	new_data(int size)
{
	t_data	data;

	data.size = size;
	data.value = malloc(size * sizeof(char));
	return (data);
}

t_map	new_map(int size)
{
	t_map	ret;

	ret.size = size;
	ret.map_arr = malloc(size * sizeof(t_data));
	return (ret);
}

t_data	mem_resize(t_data *array)
{
	t_data	new;

	new.value = malloc((array->size * 2) * sizeof(char));
	new.size = array->size * 2;
	new.value = ft_strcpy(new.value, array->value);
	free(array->value);
	return (new);
}

t_map	map_resize(t_map *map)
{
	t_map	new;
	int		i;

	i = 0;
	new.map_arr = malloc((map->size * 2) * sizeof(t_data));
	new.size = map->size * 2;
	while (i < map->size)
	{
		new.map_arr[i].key = map->map_arr[i].key;
		new.map_arr[i].value = ft_strdup(map->map_arr[i].value);
		free(map->map_arr[i].value);
		++i;
	}
	free(map->map_arr);
	return (new);
}
