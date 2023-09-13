/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:42:03 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/13 21:44:47 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *ptr;
	t_list *del;

	ptr = *lst;
	while (ptr)
	{
		del = ptr;
		ptr = ptr->next;
		ft_lstdelone(*del, (*del));
	}
	free(lst)
}