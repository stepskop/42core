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
	int	success;

	success = 0;
	avg = get_avg(a);
	while (set_index(a) > 6 && !is_sorted(*a) && (success == 0))
	{
		if ((*a)->value < avg)
		{
			success += !push((t_push){a, b}, ops);
			avg = get_avg(a);
		}
		else
			success += !rotate(a, ops);
	}
	return (success == 0);
}

static int	push_back(t_stack **a, t_stack **b, t_ops **ops)
{
	int		success;
	t_stack	*cheap;

	success = 0;
	cheap = *b;
	while (*b && (success == 0))
	{
		set_props(b, a);
		cheap = set_cost(b, a);
		success += !push_node((t_push){b, a}, cheap, ops);
	}
	return (success == 0);
}

static int	sort_base(t_stack **stk, t_stack **swp, t_ops **ops, int size)
{
	t_stack	*min;
	t_stack	*curr;
	int		success;

	success = 0;
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
		success += !s_rot(stk, min, ops);
	success += !push((t_push){stk, swp}, ops);
	success += !sort_base(stk, swp, ops, size - 1);
	success += !push((t_push){swp, stk}, ops);
	return (success == 0);
}

int	sort_n(t_stack **a, t_stack **b, t_ops **ops)
{
	int		a_len;
	int		success;
	t_stack	*curr;

	success = 0;
	a_len = set_index(a);
	if (a_len > 6)
		success += !push_all(a, b, ops);
	if (a_len > 6)
		a_len = 6;
	if (!is_sorted(*a))
		success += !sort_base(a, b, ops, a_len);
	set_props(b, a);
	success += !push_back(a, b, ops);
	curr = *a;
	while (curr && curr->next && (curr->value < curr->next->value))
		curr = curr->next;
	while (curr->next)
		success += !s_rot(a, curr->next, ops);
	return (success == 0);
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
