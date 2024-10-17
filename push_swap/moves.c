/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:48:27 by username          #+#    #+#             */
/*   Updated: 2024/10/11 23:49:27 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stk, t_ops **ops)
{
	if (!(*stk) || !(*stk)->next)
		return (1);
	*stk = (*stk)->next;
	(*stk)->prev->prev = (*stk);
	(*stk)->prev->next = (*stk)->next;
	if ((*stk)->next)
		(*stk)->next->prev = (*stk)->prev;
	(*stk)->next = (*stk)->prev;
	(*stk)->prev = NULL;
	set_index(stk);
	if ((*stk)->stk_e == A)
		return (add_op(ops, SWAP_A));
	else
		return (add_op(ops, SWAP_B));
}

int	rotate(t_stack **stk, t_ops **ops)
{
	t_stack	*last;

	last = *stk;
	if (!last || !last->next)
		return (1);
	while (last->next)
		last = last->next;
	last->next = *stk;
	*stk = (*stk)->next;
	last->next->prev = last;
	(*stk)->prev = NULL;
	last->next->next = NULL;
	set_index(stk);
	if ((*stk)->stk_e == A)
		return (add_op(ops, ROTATE_A));
	else
		return (add_op(ops, ROTATE_B));
}

int	rrotate(t_stack **stk, t_ops **ops)
{
	t_stack	*last;

	last = *stk;
	if (!last || !last->next)
		return (1);
	while (last->next)
		last = last->next;
	last->next = *stk;
	last->prev->next = NULL;
	last->prev = NULL;
	*stk = last;
	last->next->prev = last;
	set_index(stk);
	if ((*stk)->stk_e == A)
		return (add_op(ops, RROTATE_A));
	else
		return (add_op(ops, RROTATE_B));
}

int	push(t_push push_d, t_ops **ops)
{
	t_stack	*new;

	new = *(push_d.from);
	if (!new)
		return (0);
	*(push_d.from) = (*(push_d.from))->next;
	if (*(push_d.from))
		(*(push_d.from))->prev = NULL;
	new->prev = NULL;
	new->stk_e = !((int)(new->stk_e));
	if (!*(push_d.to))
	{
		*(push_d.to) = new;
		new->next = NULL;
	}
	else
	{
		new->next = *(push_d.to);
		new->next->prev = new;
		*(push_d.to) = new;
	}
	if ((*(push_d.to))->stk_e == A)
		return (set_props(push_d.to, push_d.from), add_op(ops, PUSH_A));
	else
		return (set_props(push_d.from, push_d.to), add_op(ops, PUSH_B));
}

int	s_rot(t_stack **stk, t_stack *node, t_ops **ops)
{
	if (node->upper)
	{
		if (!rotate(stk, ops))
			return (0);
	}
	else if (!rrotate(stk, ops))
		return (0);
	return (1);
}
