/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:12:48 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/16 16:12:50 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > *s2)
			return (1);
		if (*s1 < *s2)
			return (-1);
		++s1;
		++s2;
	}
	if (*s1 != '\0')
		return (1);
	else if (*s2 != '\0')
		return (-1);
	return (0);
}
