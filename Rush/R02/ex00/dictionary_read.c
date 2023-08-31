/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:46:42 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/27 17:46:44 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	open_dictionary(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	return (fd);
}

int	create_dictionary(char *path, t_map *map)
{
	int	fd;

	fd = open_dictionary(path);
	if (fd == FAIL)
		return (FAIL);
	if (read_dictionary(fd, map) == FAIL)
		return (FAIL);
	close(fd);
	return (SUCCESS);
}

int	sort_and_check(int j, t_map *map, t_data *data)
{
	map->size = j;
	sort(map->map_arr, map->size);
	if (check_repeated(map, map->size) == FAIL)
		return (FAIL);
	free(data->value);
	return (SUCCESS);
}

int	read_dictionary(int fd, t_map *map)
{
	int		j;
	char	c;
	int		aux;
	t_data	data;

	init(&j, map, &data);
	aux = read(fd, &c, 1);
	while (aux != 0)
	{
		if (c == '\n')
		{
			aux = read(fd, &c, 1);
			continue ;
		}
		if (read_key(fd, &data, &c) == FAIL || pass_through(&c, fd) == FAIL
			|| read_value(&data, &c, fd) == FAIL)
			return (FAIL);
		map->map_arr[j].key = data.key;
		map->map_arr[j].value = ft_strdup(data.value);
		if (j == map->size - 1)
			*map = map_resize(map);
		++j;
		aux = read(fd, &c, 1);
	}
	return (sort_and_check(j, map, &data));
}

void	init(int *j, t_map *map, t_data *data)
{
	*j = 0;
	*map = new_map(INI_TAM);
	*data = new_data(INI_TAM);
}
