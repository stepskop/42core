/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:51:31 by username          #+#    #+#             */
/*   Updated: 2024/10/10 22:42:57 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_index(t_stack **stk)
{
	int		i;
	int		size;
	t_stack	*curr;

	curr = *stk;
	i = 0;
	while (curr)
	{
		curr->index = i++;
		curr->upper = 1;
		curr->price = 0;
		curr->cheap = 0;
		curr = curr->next;
	}
	size = i;
	while (i > (size / 2))
	{
		curr->upper = 0;
		curr = curr->prev;
		i--;
	}
	return (size);
}

t_stack	*find_target(int value, t_stack *stk)
{
	t_stack	*target;
	t_stack	*curr;

	curr = stk;
	target = stk;
	if (!stk)
		return (NULL);
	while (curr)
	{
		if (curr->value < value && \
		(value - curr->value) < (value - target->value))
			target = curr;
		curr = curr->next;
	}
	if (target->value < value)
		return (target);
	curr = stk;
	while (curr)
	{
		if (curr->value > target->value)
			target = curr;
		curr = curr->next;
	}
	return (target);
}

void	set_props(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	int		a_len;
	int		b_len;
	int		i;

	a_len = set_index(a);
	b_len = set_index(b);
	curr = *a;
	i = 0;
	while (curr)
	{
		curr->target = find_target(curr->value, *b);
		curr = curr->next;
	}
}
