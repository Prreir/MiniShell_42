/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:39:27 by lugoncal          #+#    #+#             */
/*   Updated: 2022/11/11 20:39:31 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*newlist;

	if (!lst || !f || !del)
		return (0);
	list = ft_lstnew(f(lst->content));
	if (!list)
		return (0);
	newlist = list;
	lst = lst->next;
	while (lst != 0)
	{
		newlist = ft_lstnew(f(lst->content));
		if (newlist == 0)
		{
			ft_lstclear(&list, del);
			return (0);
		}
		ft_lstadd_back(&list, newlist);
		lst = lst->next;
	}
	return (list);
}
