/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:17:56 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/20 17:17:28 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*ret;
	void	*cont;

	if (!lst || !f || !del)
		return (0);
	ret = 0;
	while (lst)
	{
		cont = (*f)(lst->content);
		new = ft_lstnew(cont);
		if (new == 0)
		{
			(*del)(cont);
			ft_lstclear(&ret, del);
			return (0);
		}
		ft_lstadd_back(&ret, new);
		lst = lst->next;
	}
	return (ret);
}
