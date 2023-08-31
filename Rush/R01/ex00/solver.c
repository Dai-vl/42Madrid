/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:54:05 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/19 19:54:07 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TAM_MAP 4
#define N_ARGS 4
#define COL_UP 0
#define COL_DOWN 1
#define ROW_LEFT 2
#define ROW_RIGHT 3
#define UNASSIGNED 0

/*
** Checks it number can be assigned to that row and column and returns 1 if it
** is possible, 0 otherwise. 
*/
int	check_row(int map[TAM_MAP][TAM_MAP], int number, int row, int col)
{
	int	i;

	i = 0;
	while (i < TAM_MAP)
	{
		if (map[row][i] == number || map[i][col] == number)
			return (0);
		++i;
	}
	return (1);
}

/*
** Looks for a cell that has the value UNASSIGNED and changes the value of row
** and col with the corresponding cell.
** Returns 1 if it finds a free cell, 0 otherwise.
*/
int	check_unassigned(int map[TAM_MAP][TAM_MAP], int *row, int *col)
{
	int	i;
	int	j;

	i = 0;
	while (i < TAM_MAP)
	{
		j = 0;
		while (j < TAM_MAP)
		{
			if (map[i][j] == UNASSIGNED)
			{
				*row = i;
				*col = j;
				return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

/*
** Calculates the element in the position of map relative to the column or
** row and the position asked.
*/
int	get_pos(int map[TAM_MAP][TAM_MAP], int i, int j, int dir)
{
	if (dir == COL_UP)
		return (map[i][j]);
	if (dir == COL_DOWN)
		return (map[TAM_MAP - i - 1][j]);
	if (dir == ROW_LEFT)
		return (map[j][i]);
	return (map[j][TAM_MAP - i - 1]);
}

/*
** This functions checks if the visibility requirements are met in the current
** map.
** Returns 1 in case they are met, 0 otherwise.
*/
int	check_vis(int vis[TAM_MAP][N_ARGS], int map[TAM_MAP][TAM_MAP], int dir)
{
	int	view;
	int	i;
	int	j;
	int	max;

	j = 0;
	while (j < N_ARGS)
	{
		view = 1;
		i = 1;
		max = get_pos(map, 0, j, dir);
		while (i < TAM_MAP)
		{
			if (get_pos(map, i, j, dir) > max)
			{
				max = get_pos(map, i, j, dir);
				++view;
			}
			++i;
		}
		if (view != vis[dir][j])
			return (0);
		++j;
	}
	return (1);
}

/*
** To solve the map the algorithm used is backtracking. This function applies 
** the necessary steps to do so.
*/
int	solve_map(int vis[TAM_MAP][N_ARGS], int map[TAM_MAP][TAM_MAP])
{
	int	row;
	int	col;
	int	num;
	int	check_vis_ret;
	int	check;

	check_vis_ret = 1;
	check = 0;
	while (check < N_ARGS && check_vis_ret)
		check_vis_ret = check_vis_ret & check_vis(vis, map, check++);
	if (!check_unassigned(map, &row, &col) && check_vis_ret)
		return (1);
	num = 1;
	while (num <= TAM_MAP)
	{
		if (check_row(map, num, row, col))
		{
			map[row][col] = num;
			if (solve_map(vis, map))
				return (1);
			map[row][col] = UNASSIGNED;
		}
		++num;
	}
	return (0);
}
