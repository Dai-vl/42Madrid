/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:47:21 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/30 13:47:22 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	update_max(t_max *max, int **dp, int i, int j)
{
	if (dp[i][j] > max->size)
	{
		max->size = dp[i][j];
		max->x = j;
		max->y = i;
	}
}	

void	find(int **dp, t_data crs, t_max *max)
{
	int		i;
	int		j;
	int		min_sq;

	max->size = 0;
	i = 0;
	while (i < crs.lines)
	{
		j = 0;
		while (j < crs.cols)
		{
			if (i == 0 || j == 0)
				update_max(max, dp, i, j);
			else if (dp[i][j] != 0 && i > 0 && j > 0)
			{
				min_sq = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
				dp[i][j] = min_sq + 1;
				update_max(max, dp, i, j);
			}
			++j;
		}
		++i;
	}
}

void	print_map(int **map, t_data crs, t_max max)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < crs.lines)
	{
		j = 0;
		while (j < crs.cols)
		{
			if (j >= max.x - max.size + 1 && i >= max.y - max.size + 1
				&& i <= max.y && j <= max.x)
				write(1, &crs.full, 1);
			else
			{
				c = translate_int(map[i][j], crs);
				write(1, &c, 1);
			}
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
	free_map(0, crs, map, 1);
}

void	free_map(char **map, t_data crs, int **dp, int mode)
{
	int	i;

	i = 0;
	if (mode == 0)
	{
		if (map == 0)
			return ;
		while (i < crs.lines && map[i] != 0)
		{
			free(map[i]);
			++i;
		}
		free(map);
		return ;
	}
	if (dp == 0)
		return ;
	while (i < crs.lines && dp[i] != 0)
	{
		free(dp[i]);
		++i;
	}
	free(dp);
}

void	solve(char	**map, t_data crs)
{
	int		**dp;
	int		i;
	int		j;
	t_max	max;

	dp = malloc(crs.lines * sizeof(int *));
	if (dp == 0)
		return ;
	i = 0;
	while (i < crs.lines)
	{
		j = 0;
		dp[i] = malloc(crs.cols * sizeof(int));
		while (j < crs.cols)
		{
			dp[i][j] = translate_char(map[i][j], crs);
			++j;
		}
		++i;
	}
	find(dp, crs, &max);
	print_map(dp, crs, max);
}
