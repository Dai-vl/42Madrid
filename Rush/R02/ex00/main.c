/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:58:57 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/26 12:58:58 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

int	check_arguments(char *str, char *path, unsigned int *num, t_map *map)
{
	int	len1;

	len1 = ft_strlen(str);
	if (len1 > MAX_INT_SIZE || (len1 == MAX_INT_SIZE
			&& ft_strncmp(str, "4294967295", len1) == 1))
	{
		ft_putstr(ERROR);
		return (FAIL);
	}
	if (ft_atoi(str, num) == FAIL)
	{
		ft_putstr(ERROR);
		return (FAIL);
	}
	if (create_dictionary(path, map) == FAIL)
	{
		ft_putstr(DICT_ERROR);
		return (FAIL);
	}
	return (SUCCESS);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		free(map->map_arr[i].value);
		++i;
	}
	free(map->map_arr);
}

void	read_input(char **str_num)
{
	int		i;
	char	c;
	int		aux;

	i = 0;
	aux = 1;
	*str_num = malloc((MAX_INT_SIZE + 1) * sizeof(char));
	read(0, &c, 1);
	while (aux > 0 && c != '\n')
	{
		(*str_num)[i] = c;
		++i;
		aux = read(0, &c, 1);
	}
	(*str_num)[i] = '\0';
}

void	store_args(int argc, char *argv[], char	**str_num, char **dic_path)
{
	if (argc == 1)
	{
		read_input(str_num);
		*dic_path = DICTIONARY;
	}
	else if (argc == 2)
	{
		*str_num = argv[1];
		*dic_path = DICTIONARY;
	}
	else
	{
		*str_num = argv[2];
		*dic_path = argv[1];
	}
}

int	main(int argc, char *argv[])
{
	unsigned int	number;
	char			*str_num;
	char			*dic_path;
	t_map			map;

	if (argc < 1 || argc > 3)
	{
		ft_putstr(ERROR);
		return (0);
	}
	store_args(argc, argv, &str_num, &dic_path);
	if (check_arguments(str_num, dic_path, &number, &map) == FAIL)
	{
		free_map(&map);
		return (0);
	}
	if (translate_number(str_num, map, ft_strlen(str_num), number) == FAIL)
	{
		free_map(&map);
		ft_putstr(DICT_ERROR);
		return (0);
	}
	free_map(&map);
	return (0);
}
