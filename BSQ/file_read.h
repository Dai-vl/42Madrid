/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:53:40 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/30 13:53:49 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_READ_H
# define FILE_READ_H

# include "utils.h"

int		check_chars(t_data *crs);

char	*read_line(t_data *crs, int fd, char *c);

char	**read_map(int fd, t_data *crs);

int		read_contents(int fd, t_data *crs);

int		open_file(char *path);

#endif
