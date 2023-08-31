/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:31:22 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/30 13:31:23 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_read.h"

int	check_chars(t_data *crs)
{
	if (crs->lines == FAIL || crs->lines == 0)
		return (FAIL);
	if (crs->empty == crs->full || crs->full == crs->obs
		|| crs->obs == crs->empty)
		return (FAIL);
	if (!(crs->empty >= 32 && crs->empty <= 126)
		|| !(crs->full >= 32 && crs->full <= 126)
		|| !(crs->obs >= 32 && crs->obs <= 126))
		return (FAIL);
	return (SUCCESS);
}

char	*read_line(t_data *crs, int fd, char *c)
{
	int		aux;
	int		j;
	int		curr_size;
	char	*map;

	curr_size = crs->cols;
	if (crs->cols == -1)
		curr_size = IN_LINE_SIZE;
	map = malloc(curr_size * sizeof(char));
	aux = read(fd, c, 1);
	j = 0;
	while (aux > 0 && *c != '\n' && val_symbol(*c, *crs))
	{
		map[j] = *c;
		aux = read(fd, c, 1);
		if (++j == curr_size)
			map = ft_realloc(map, &curr_size);
	}
	map[j] = '\0';
	if (crs->cols == -1)
		crs->cols = j;
	if (aux == FAIL || (*c != '\n' && !val_symbol(*c, *crs)) || j != crs->cols)
		return (free_arr(map));
	return (map);
}

char	**read_map(int fd, t_data *crs)
{
	char	**map;
	int		i;
	char	c;

	crs->cols = -1;
	i = 0;
	map = malloc(crs->lines * sizeof(char *));
	while (i < crs->lines)
	{
		map[i] = read_line(crs, fd, &c);
		if (map[i] == 0 || *map[i] == '\0')
		{
			free_map(map, *crs, 0, 0);
			return (0);
		}
		++i;
	}
	if (fd != 0 && ((i == crs->lines && read(fd, &c, 1) > 0) || c != '\n'))
	{
		free_map(map, *crs, 0, 0);
		return (0);
	}
	return (map);
}

int	read_contents(int fd, t_data *crs)
{
	char	*line;
	int		aux;
	int		i;
	char	c;

	i = 0;
	line = malloc((MAX_INT_SIZE + 4) * sizeof(char));
	if (line == 0)
	{	
		free(line);
		return (FAIL);
	}
	aux = read(fd, &c, 1);
	while (aux == 1 && c != '\n')
	{
		line[i++] = c;
		aux = read(fd, &c, 1);
	}
	if (aux == FAIL)
	{
		free(line);
		return (FAIL);
	}
	store_chars(crs, line, i);
	return (check_chars(crs));
}

int	open_file(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == FAIL)
		return (FAIL);
	return (fd);
}
