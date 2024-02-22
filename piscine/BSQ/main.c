/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamato-h <mamato-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:47:00 by mamato-h          #+#    #+#             */
/*   Updated: 2023/08/29 16:14:20 by mamato-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_read.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > *s2)
			return (1);
		if (*s1 < *s2)
			return (-1);
		++s1;
		++s2;
	}
	if (*s1 != '\0')
		return (1);
	else if (*s2 != '\0')
		return (-1);
	return (0);
}

char	*free_arr(char *arr)
{
	free(arr);
	return (0);
}

int	solve_argument(int fd, t_data *characters, char **map)
{
	if (fd == FAIL)
		return (FAIL);
	if (read_contents(fd, characters) == FAIL)
		return (FAIL);
	map = read_map(fd, characters);
	if (map == 0)
		return (FAIL);
	close(fd);
	if (fd == 0)
		ft_putstr("\n");
	solve(map, *characters);
	free_map(map, *characters, 0, 0);
	return (SUCCESS);
}

int	check_args(int argc, char **argv, t_data *characters, char **map)
{
	int		aux;
	int		i;

	aux = SUCCESS;
	if (argc == 1)
	{
		aux = solve_argument(0, characters, map);
		return (aux);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			aux = solve_argument(open_file(argv[i]), characters, map);
			if (aux == FAIL)
				ft_putstr("map error\n");
			if (i < argc - 1)
				ft_putstr("\n");
			++i;
		}
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	characters;
	char	**map;

	map = 0;
	if (check_args(argc, argv, &characters, map) == FAIL)
	{
		ft_putstr("map error");
		free_map(map, characters, 0, 0);
	}
	return (0);
}
