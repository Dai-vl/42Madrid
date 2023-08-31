/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_data_read.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:46:18 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/27 17:46:20 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	read_key(int fd, t_data *data, char *c)
{
	int		i;
	char	num_buffer[MAX_INT_SIZE + 1];
	int		aux;

	aux = 1;
	i = 0;
	while (aux == 1 && *c >= '0' && *c <= '9')
	{
		num_buffer[i] = *c;
		aux = read(fd, c, 1);
		++i;
	}
	if ((*c < '0' || *c > '9') && *c != ' ' && *c != ':')
		return (FAIL);
	num_buffer[i] = '\0';
	if (ft_atoi(num_buffer, &data->key) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	pass_through(char *c, int fd)
{
	while (*c != ':' && read(fd, c, 1) == 1 && *c == ' ')
		;
	if (*c != ':')
		return (FAIL);
	while (read(fd, c, 1) == 1 && *c == ' ')
		;
	return (SUCCESS);
}

int	read_value(t_data *data, char *c, int fd)
{
	int		i;
	int		aux;

	aux = 1;
	i = 0;
	while (aux && *c != '\n' && *c >= 32 && *c <= 126)
	{
		data->value[i] = *c;
		++i;
		if (i == data->size - 1)
			*data = mem_resize(data);
		aux = read(fd, c, 1);
	}
	if (*c != '\n' && (*c < 32 || *c > 126))
		return (FAIL);
	while (i > 0 && data->value[i - 1] == ' ')
		--i;
	data->value[i] = '\0';
	return (SUCCESS);
}
