/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:36:23 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/22 13:36:24 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	arg;

	if (argc == 1)
		return (0);
	arg = argc - 1;
	while (arg > 0)
	{
		while (*argv[arg])
		{
			write(1, argv[arg], 1);
			++argv[arg];
		}
		write(1, "\n", 1);
		--arg;
	}
}
