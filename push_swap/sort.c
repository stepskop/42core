/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:11:15 by username          #+#    #+#             */
/*   Updated: 2024/10/14 02:13:03 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_all(t_stack **a, t_stack **b, t_ops **ops)
{
	int	avg;

	avg = get_avg(a);
	while (set_index(a) >= 5 && !is_sorted(*a))
	{
		if ((*a)->value < avg)
		{
			if (!push((t_push){a, b}, ops))
				return (0);
			avg = get_avg(a);
		}
		else if (!rotate(a, ops))
			return (0);
	}
	return (1);
}

static int	push_back(t_stack **a, t_stack **b, t_ops **ops)
{
	t_stack	*cheap;

	cheap = *b;
	while (*b)
	{
		set_props(b, a);
		cheap = set_cost(b, a);
		if (!push_node((t_push){b, a}, cheap, ops))
			return (0);
	}
	return (1);
}

static int	sort_base(t_stack **stk, t_stack **swp, t_ops **ops, int size)
{
	t_stack	*min;
	t_stack	*curr;

	if (size == 3)
		return (sort_three(stk, ops));
	curr = *stk;
	min = *stk;
	while (curr)
	{
		if (curr->value < min->value)
			min = curr;
		curr = curr->next;
	}
	while (min->index)
		if (!s_rot(stk, min, ops))
			return (0);
	if (is_sorted(*stk))
		return (1);
	if (!push((t_push){stk, swp}, ops) || \
	!sort_base(stk, swp, ops, size - 1) || \
	!push((t_push){swp, stk}, ops))
		return (0);
	return (1);
}

int	sort_n(t_stack **a, t_stack **b, t_ops **ops)
{
	int		a_len;
	t_stack	*curr;

	a_len = set_index(a);
	if (a_len > 5)
		if (!push_all(a, b, ops))
			return (0);
	if (a_len > 5)
		a_len = 5;
	if (!is_sorted(*a))
		if (!sort_base(a, b, ops, a_len))
			return (0);
	if (!push_back(a, b, ops))
		return (0);
	curr = *a;
	while (curr && curr->next && (curr->value < curr->next->value))
		curr = curr->next;
	while (curr->next)
		if (!s_rot(a, curr->next, ops))
			return (0);
	return (1);
}

int	sort(t_stack **a, t_stack **b, t_ops **ops)
{
	int	stk_len;

	stk_len = set_index(a);
	if (is_sorted(*a))
		return (1);
	set_props(a, b);
	if (stk_len == 2)
		return (swap(a, ops));
	else if (stk_len == 3)
		return (sort_three(a, ops));
	else if (stk_len > 3)
		return (sort_n(a, b, ops));
	return (0);
}
