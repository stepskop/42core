/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:35:32 by username          #+#    #+#             */
/*   Updated: 2024/10/12 01:37:49 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

enum e_moves	optimize_op(t_ops *op)
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_ops	*ops;

	a = NULL;
	b = NULL;
	ops = NULL;
	if (argc < 2)
		return (write(2, "Error\n", 6), 1);
	if (argc > 2)
		parse_mul(&a, argc, argv);
	else
		parse_one(&a, argv[1]);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	if (sort(&a, &b, &ops))
	{
		// t_stack *curr = a;
		// while (curr)
		// {
		// 	ft_printf("%i\n", curr->value);
		// 	curr = curr->next;
		// }
		return (print_ops(ops), free_all(&a, &b, &ops), 0);
	}
	return (write(2, "Error\n", 6), 1);
}
