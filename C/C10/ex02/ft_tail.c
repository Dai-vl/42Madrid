/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:15:06 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/31 15:15:09 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>
#include <fcntl.h>

#define TAM 4096

void	ft_putstr(char *str, int fd)
{
	while (*str != '\0')
	{
		write(fd, str, 1);
		str++;
	}
}

void	ft_tail_in(void)
{
	char	buffer[TAM];
	int		aux;

	aux = read(STDIN_FILENO, buffer, TAM);
	while (aux != 0 && aux != -1)
	{
		buffer[aux] = '\0';
		aux = read(STDIN_FILENO, buffer, TAM);
	}
}

void	print_error(char *prog, char *path, int error)
{
	ft_putstr(basename(prog), 2);
	ft_putstr(": ", 2);
	ft_putstr(basename(path), 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(error), 2);
	ft_putstr("\n", 2);
}

void	ft_tail(int fd, int off)
{
	char	buffer[TAM];
	int		aux;

	aux = read(fd, buffer, TAM);
	while (aux != 0 && aux != -1)
	{
		buffer[aux] = '\0';
		write(1, buffer, aux);
		aux = read(fd, buffer, TAM);
	}
}

void	print_name(char *path)
{
	ft_putstr("==> ", 1);
	ft_putstr(basename(path), 1);
	ft_putstr(" <==\n", 1);
}

void	print_files(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			print_error(argv[0], argv[i], errno);
		else
		{
			print_name(argv[i]);
			ft_tail(fd, 0);
			if (i < argc - 1)
				ft_putstr("\n", 1);
		}
		++i;
	}
}

void	print_buffer(int off, int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			print_error(argv[0], argv[i], errno);
		else
		{
			print_name(argv[i]);
			ft_tail(fd, off);
			if (i < argc - 1)
				ft_putstr("\n", 1);
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	if (argc == 1)
		ft_tail_in();
	else if (argc == 2)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			print_error(argv[0], argv[i], errno);
		ft_tail(fd, 0);
	}
	else if (*argv[2] != '-')
		print_files(argc, argv);
	else
	{
		if (*argv[3] == 'c')
			print_buffer(argv[4], argc, argv);
	}
}
