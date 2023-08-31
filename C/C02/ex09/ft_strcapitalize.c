/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:23:58 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/13 19:24:00 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
char	*ft_strcapitalize(char *str)
{
	char	*aux;
	int		cap;

	aux = str;
	cap = 1;
	while (*aux != '\0')
	{
		if ((*aux >= 'a' && *aux <= 'z') || (*aux >= 'A' && *aux <= 'Z')
			|| (*aux >= '0' && *aux <= '9'))
		{
			if (*aux >= 'a' && *aux <= 'z' && cap == 1)
				*aux -= 32;
			else if (*aux >= 'A' && *aux <= 'Z' && cap == 0)
				*aux += 32;
			cap = 0;
		}
		else
			cap = 1;
		++aux;
	}
	return (str);
}

/*int main()
{
	char ret[] = "SaluT, comment tU Vas ? 42Mots Quarante-Deux; Cinquante+Et+Un a";
	char *aux = ft_strcapitalize(ret);
	printf("%s", aux);
	return (0);
}*/