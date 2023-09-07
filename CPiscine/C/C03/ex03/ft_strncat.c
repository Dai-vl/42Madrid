/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:58:56 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/16 20:58:58 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*ps;
	char			*pd;
	unsigned int	i;

	ps = src;
	pd = dest;
	i = 0;
	while (*pd != '\0')
	{
		++pd;
	}
	while (*ps != '\0' && i < nb)
	{
		*pd = *ps;
		++pd;
		++ps;
		++i;
	}
	*pd = '\0';
	return (dest);
}
