/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:28:40 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/18 15:34:24 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*new_lst;
	t_list	*new_cell;

	curr = lst;
	new_lst = (void *)0;
	if (!lst || !f || !del)
		return ((void *)0);
	while (curr)
	{
		new_cell = ft_lstnew(f(curr->content));
		if (!new_cell)
		{
			ft_lstclear(&new_lst, del);
			return ((void *)0);
		}
		ft_lstadd_back(&new_lst, new_cell);
		curr = curr->next;
	}
	return (new_lst);
}
