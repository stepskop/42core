/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:10:18 by username          #+#    #+#             */
/*   Updated: 2024/10/14 01:53:04 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_op(t_ops **ops, enum e_moves move)
{
	t_ops	*new;
	t_ops	*i;

	if (!ops)
		return (0);
	new = malloc(1 * sizeof(t_stack));
	if (!new)
		return (free_ops(ops), *ops = NULL, 0);
	new->op = move;
	new->next = NULL;
	new->prev = NULL;
	if (!*ops)
		*ops = new;
	else
	{
		i = *ops;
		while (i->next)
			i = i->next;
		i->next = new;
		new->prev = i;
	}
	return (1);
}

static enum e_moves	optimize_op(t_ops *op)
{
	enum e_moves	curr;
	enum e_moves	next;

	curr = op->op;
	if (!op->next)
		return (curr);
	next = op->next->op;
	if ((curr == ROTATE_A && next == ROTATE_B) || \
	(curr == ROTATE_B && next == ROTATE_A))
		return (ROTATE_AB);
	else if ((curr == RROTATE_A && next == RROTATE_B) || \
	(curr == RROTATE_B && next == RROTATE_A))
		return (RROTATE_AB);
	else if ((curr == SWAP_A && next == SWAP_B) || \
	(curr == SWAP_B && next == SWAP_A))
		return (SWAP_AB);
	return (curr);
}

void	print_ops(t_ops *ops)
{
	t_ops			*curr;
	enum e_moves	m;
	const char		*move_str[] = {
	[SWAP_A] = "sa",
	[SWAP_B] = "sb",
	[PUSH_A] = "pa",
	[PUSH_B] = "pb",
	[ROTATE_A] = "ra",
	[ROTATE_B] = "rb",
	[RROTATE_A] = "rra",
	[RROTATE_B] = "rrb",
	[SWAP_AB] = "ss",
	[ROTATE_AB] = "rr",
	[RROTATE_AB] = "rrr"
	};

	curr = ops;
	while (curr)
	{
		m = optimize_op(curr);
		curr = curr->next;
		if (m == SWAP_AB || m == RROTATE_AB || m == ROTATE_AB)
			curr = curr->next;
		ft_printf("%s\n", move_str[m]);
	}
}
