/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:38:34 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/14 18:17:06 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (0);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}