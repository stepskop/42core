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
	while ((set_index(a) > 6) && !is_sorted(*a))
	{
		set_props(a, b, A);
		cheapest = set_cost(a, b);
		success += !push_node((t_push){a, b}, cheapest, ops);
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
		success += !push_node((t_push){b, a}, curr, ops);
		curr = tmp;
	}
	return (success == 0);
}

static int sort_base(t_stack **stk, t_stack **swp, t_ops **ops, int size)
{
    t_stack *min;
    t_stack *curr;

    if (size == 3)
    {
        sort_three(stk, ops);
        return (1);
    }
    curr = *stk;
    min = *stk;
    while (curr)
    {
        if (curr->value < min->value)
            min = curr;
        curr = curr->next;
    }
    while (min->index)
        s_rot(stk, min, ops);
    push((t_push){stk, swp}, ops);
    sort_base(stk, swp, ops, size - 1);
    push((t_push){swp, stk}, ops);
    return (1);
}

int	sort_n(t_stack **a, t_stack **b, t_ops **ops)
{
	int		a_len;
	int		success;
	t_stack	*curr;

	success = 0;
	success += !push((t_push){a, b}, ops);
	a_len = set_index(a);
	if (a_len > 6)
		success += !push((t_push){a, b}, ops);
	if (a_len > 6)
		success += !push_all(a, b, ops);
	if (!is_sorted(*a))
		success += !sort_base(a, b, ops, 6);
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
	set_props(a, b, A);
	if (stk_len == 2)
		return (swap(a, ops));
	else if (stk_len == 3)
		return (sort_three(a, ops));
	else if (stk_len > 3)
		return (sort_n(a, b, ops));
	return (1);
}
