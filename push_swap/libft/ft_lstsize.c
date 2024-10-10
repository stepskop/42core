/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:51:41 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/18 14:51:38 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*curr_node;

	count = 0;
	curr_node = lst;
	while (curr_node)
	{
		count++;
		curr_node = curr_node->next;
	}
	return (count);
}
