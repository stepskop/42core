/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:51:31 by username          #+#    #+#             */
/*   Updated: 2024/10/12 02:40:10 by username         ###   ########.fr       */
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
		curr->upper = 0;
		curr = curr->next;
	}
	size = i;
	curr = *stk;
	while (i > (size / 2))
	{
		curr->upper = 1;
		curr = curr->next;
		i--;
	}
	return (size);
}

static t_stack	*find_target(int value, t_stack *stk)
{
	t_stack	*target;
	t_stack	*curr;

	if (!stk)
		return (NULL);
	curr = stk;
	target = NULL;
	while (curr)
	{
		if (curr->value > value && (!target || curr->value < target->value))
			target = curr;
		curr = curr->next;
	}
	if (!target)
	{
		curr = stk;
		target = stk;
		while (curr)
		{
			if (curr->value < target->value)
				target = curr;
			curr = curr->next;
		}
	}
	return (target);
}

void	set_props(t_stack **a, t_stack **b)
{
	t_stack	*curr;	

	set_index(a);
	set_index(b);
	curr = *a;
	while (curr)
	{
		curr->target = find_target(curr->value, *b);
		curr = curr->next;
	}
}

int	push_node(t_push push_d, t_stack *node, t_ops **ops)
{
	int		node_moves;
	int		target_moves;
	int		i;

	i = 0;
	node_moves = top_price(node, set_index(push_d.from));
	target_moves = top_price(node->target, set_index(push_d.to));
	while (i < node_moves && i < target_moves)
	{
		if (!s_rot(push_d.from, node, ops) || \
		!s_rot(push_d.to, node->target, ops))
			return (0);
		i++;
	}
	while (i < node_moves--)
		if (!s_rot(push_d.from, node, ops))
			return (0);
	while (i < target_moves--)
		if (!s_rot(push_d.to, node->target, ops))
			return (0);
	if (!push(push_d, ops))
		return (0);
	return (1);
}

int	get_avg(t_stack **stk)
{
	long long	sum;
	int			average;
	int			size;
	t_stack		*curr;

	sum = 0;
	size = 0;
	curr = *stk;
	while (curr)
	{
		sum += curr->value;
		size++;
		curr = curr->next;
	}
	average = sum / size;
	return (average);
}
