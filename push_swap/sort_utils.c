/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:24:45 by username          #+#    #+#             */
/*   Updated: 2024/10/11 23:18:05 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*curr;

	curr = a;
	while (curr->next)
	{
		if (!(curr->value < curr->next->value))
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	top_price(t_stack *node, int stack_size)
{
	if (node->upper)
		return (node->index);
	else
		return (stack_size - node->index);
}

static int	get_price(t_stack **a, t_stack **b, t_stack *node)
{
	int	price;
	int	a_len;
	int	b_len;

	a_len = set_index(a);
	b_len = set_index(b);
	if ((node->upper && node->target->upper) || \
	(!node->upper && !node->target->upper))
	{
		if (top_price(node, a_len) > top_price(node->target, b_len))
			price = top_price(node, a_len);
		else
			price = top_price(node->target, b_len);
	}
	else
		price = top_price(node, a_len) + top_price(node->target, b_len);
	return (price);
}

t_stack	*set_cost(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	t_stack	*cheap;

	curr = *a;
	cheap = *a;
	while (curr)
	{
		curr->price = get_price(a, b, curr);
		if (curr->price < cheap->price)
			cheap = curr;
		curr->cheap = 0;
		curr = curr->next;
	}
	cheap->cheap = 1;
	return (cheap);
}
