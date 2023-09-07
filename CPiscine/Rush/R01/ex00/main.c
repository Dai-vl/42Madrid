/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4x4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:03:08 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/19 18:03:09 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define TAM_MAP 4
#define N_ARGS 4
#define COL_UP 0
#define COL_DOWN 1
#define ROW_LEFT 2
#define ROW_RIGHT 3

int		prep_and_solve(int vis[TAM_MAP][N_ARGS], int map[TAM_MAP][TAM_MAP]);

/*
** Receives a matrix with the values for column up, column down,
** row left and row right.
** Returns 1 if is a valid map disposition, 0 otherwise.

If the value from row left and row right are the same and they are not 2, 
it is impossible to solve. The same happens for column up and column down.
If the value from row left is 4 and the value from row right is not 1, it 
is impossible to solve. The same happens for column up and column down.
*/
int	valid_combination(int vis[TAM_MAP][N_ARGS], int i, int pos1, int pos2)
{
	if (vis[pos1][i] == vis[pos2][i]
		&& vis[pos1][i] != 2)
		return (0);
	if ((vis[pos1][i] == 4 && vis[pos2][i] != 1)
		|| (vis[pos1][i] != 1 && vis[pos2][i] == 4))
		return (0);
	return (1);
}

/*
** Receives a matrix with the values for column up, column down, 
** row left and row right.
** Returns 1 if is a valid map disposition, 0 otherwise.	
*/
int	valid_map(int visibility[TAM_MAP][N_ARGS])
{
	int	i;
	int	valid;

	valid = 1;
	i = 0;
	while (i < TAM_MAP && valid)
	{
		if (!valid_combination(visibility, i, COL_UP, COL_DOWN)
			|| !valid_combination(visibility, i, ROW_LEFT, ROW_RIGHT))
			valid = 0;
		++i;
	}
	return (valid);
}

/*
** Receives the string with the values for col up, col down, row left and row 
** right separated by spaces(str) and saves those values in visibility.
** Returns count divided by two to check if there are enough values without 
** counting the spaces.
*/
int	parse_args(char *str, int visibility[TAM_MAP][N_ARGS])
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < TAM_MAP)
	{
		j = 0;
		while (j < N_ARGS)
		{
			if (str[count] < '1' || str[count] > '4')
				return (0);
			visibility[i][j] = str[count] - '0';
			count += 2;
			++j;
		}
		++i;
	}
	return (count / 2);
}

/*
** Prints the map which is passed as an argument.
*/
void	print_map(int map[TAM_MAP][TAM_MAP])
{
	int		i;
	int		j;
	char	cell;

	i = 0;
	while (i < TAM_MAP)
	{
		j = 0;
		while (j < N_ARGS)
		{
			cell = map[i][j] + '0';
			write(1, &cell, 1);
			if (j != N_ARGS - 1)
				write(1, " ", 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}

int	main(int argc, char *argv[])
{
	int	count;
	int	visibility[TAM_MAP][N_ARGS];
	int	map[TAM_MAP][TAM_MAP];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	count = parse_args(argv[1], visibility);
	if (count != TAM_MAP * N_ARGS || !valid_map(visibility)
		|| !prep_and_solve(visibility, map))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	print_map(map);
	return (0);
}
