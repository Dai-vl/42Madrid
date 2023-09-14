/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:42:03 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/14 23:14:13 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*rm;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		rm = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(rm, (*del));
	}
	*lst = 0;
}
