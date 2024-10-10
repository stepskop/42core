/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:24:45 by username          #+#    #+#             */
/*   Updated: 2024/10/10 22:28:27 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*curr;

	curr = a;
	while (curr)
	{
		if (!(curr->value < curr->next->value))
			return (0);
		curr = curr->next;
	}
	return (1);
}
