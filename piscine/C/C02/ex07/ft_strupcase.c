/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:55:51 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/13 17:55:53 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*aux;

	aux = str;
	while (*aux != '\0')
	{
		if (*aux >= 'a' && *aux <= 'z')
		{
			*aux -= 32;
		}
		++aux;
	}
	return (str);
}