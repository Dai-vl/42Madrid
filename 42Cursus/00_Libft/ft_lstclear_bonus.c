/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:42:03 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/14 19:09:48 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*rm;

	ptr = *lst;
	while (ptr)
	{
		rm = ptr;
		ptr = ptr->next;
		ft_lstdelone(rm, (*del));
	}
	free(lst);
}
