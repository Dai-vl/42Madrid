/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:32:52 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/22 13:32:53 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	arg;

	if (argc == 1)
		return (0);
	arg = 1;
	while (arg < argc)
	{
		while (*argv[arg])
		{
			write(1, argv[arg], 1);
			++argv[arg];
		}
		write(1, "\n", 1);
		++arg;
	}
}
