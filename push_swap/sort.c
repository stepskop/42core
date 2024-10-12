/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:11:15 by username          #+#    #+#             */
/*   Updated: 2024/10/12 02:39:23 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_all(t_stack **a, t_stack **b, t_ops **ops)
{
	t_stack	*cheapest;
	int		success;

	success = 0;
	while (set_index(a) > 3)
	{
		set_props(a, b, A);
		cheapest = set_cost(a, b);
		success += !push_node((t_push){A, B, a, b}, cheapest, ops);
	}
	return (success == 0);
}

static int	push_back(t_stack **a, t_stack **b, t_ops **ops)
{
	int		success;
	t_stack	*curr;
	t_stack	*tmp;

	success = 0;
	curr = *b;
	while (curr)
	{
		tmp = curr->next;
		set_props(b, a, B);
		success += !push_node((t_push){B, A, b, a}, curr, ops);
		curr = tmp;
	}
	return (success == 0);
}

static int	sort_three(t_stack **stk, t_ops **ops, enum e_stacks stk_e)
{
	t_stack	*max;
	t_stack	*curr;
	int		success;

	success = 0;
	curr = *stk;
	max = *stk;
	while (curr)
	{
		if (curr->value > max->value)
			max = curr;
		curr = curr->next;
	}
	if (max->index == 0)
		success += !rotate(stk, ops, stk_e);
	else if (max->index == 1)
		success += !rrotate(stk, ops, stk_e);
	if ((*stk)->value > (*stk)->next->value)
		success += !swap(stk, ops, stk_e);
	return (success == 0);
}

int	sort_n(t_stack **a, t_stack **b, t_ops **ops)
{
	int		a_len;
	int		success;
	t_stack	*curr;

	success = 0;
	success += !push((t_push){A, B, a, b}, ops);
	a_len = set_index(a);
	if (a_len > 3)
		success += !push((t_push){A, B, a, b}, ops);
	if (a_len > 3)
		success += !push_all(a, b, ops);
	success += !sort_three(a, ops, A);
	success += !push_back(a, b, ops);
	curr = *a;
	while (curr && curr->next && (curr->value < curr->next->value))
		curr = curr->next;
	while (curr->next)
		success += !s_rot(a, curr->next, ops, A);
	return (success == 0);
}

int	sort(t_stack **a, t_stack **b, t_ops **ops)
{
	int	stk_len;

	stk_len = set_index(a);
	if (is_sorted(*a))
		return (1);
	set_props(a, b, A);
	if (stk_len == 2)
		return (swap(a, ops, A));
	else if (stk_len == 3)
		return (sort_three(a, ops, A));
	else if (stk_len > 3)
		return (sort_n(a, b, ops));
	return (1);
}
