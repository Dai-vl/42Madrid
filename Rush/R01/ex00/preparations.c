/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:02:21 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/19 19:02:22 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TAM_MAP 4
#define N_ARGS 4
#define COL_UP 0
#define COL_DOWN 1
#define ROW_LEFT 2
#define ROW_RIGHT 3
#define UNASSIGNED 0

int	solve_map(int vis[TAM_MAP][N_ARGS], int map[TAM_MAP][TAM_MAP]);

/*
** This function receives the map, the direction (which can be either row or
** column) and the position in the map.
** It is called when preparing the map if a vision of 4 is found and filles
** the row or column that position indicates with [1,2,3,4].
*/
void	fill_row_col(int map[TAM_MAP][TAM_MAP], int dir, int pos)
{
	int	i;

	i = 0;
	while (i < TAM_MAP && dir == COL_UP)
	{
		map[i][pos] = i + 1;
		++i;
	}
	while (i < TAM_MAP && dir == COL_DOWN)
	{
		map[i][pos] = TAM_MAP - i;
		++i;
	}
	while (i < TAM_MAP && dir == ROW_LEFT)
	{
		map[pos][i] = i + 1;
		++i;
	}
	while (i < TAM_MAP && dir == ROW_RIGHT)
	{
		map[pos][i] = TAM_MAP - i;
		++i;
	}
}

/*
** Receives the visibility of every column and row and prepares the map,
** so that every row/column that has 4 visible boxes is filled with [1,2,3,4]
** which is the only posible combination. 
*/
void	fill_fours(int vis[TAM_MAP][N_ARGS], int map[TAM_MAP][TAM_MAP])
{
	int	i;
	int	j;

	i = 0;
	while (i < TAM_MAP)
	{
		j = 0;
		while (j < N_ARGS)
		{
			if (vis[i][j] == 4)
				fill_row_col(map, i, j);
			++j;
		}
		++i;
	}
}

/*
** Initializes the map with UNASSIGNED (cells don't have an assigned number yet).
*/
void	initialize_map(int map[TAM_MAP][TAM_MAP])
{	
	int	i;
	int	j;

	i = 0;
	while (i < TAM_MAP)
	{
		j = 0;
		while (j < TAM_MAP)
		{
			map[i][j] = UNASSIGNED;
			++j;
		}
		++i;
	}
}

/*
** Calls the corresponding functions to prepare the map and finally
** calls the function to solve it.
*/
int	prep_and_solve(int vis[TAM_MAP][N_ARGS], int map[TAM_MAP][TAM_MAP])
{
	initialize_map(map);
	fill_fours(vis, map);
	return (solve_map(vis, map));
}
