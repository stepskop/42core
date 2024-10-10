/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:35:32 by username          #+#    #+#             */
/*   Updated: 2024/10/10 18:18:32 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	print_ops(t_ops *ops)
{
	t_ops		*curr;
	int			i;
	const char	*move_str[] = {
	[SWAP_A] = "sa\n",
	[SWAP_B] = "sb\n",
	[PUSH_A] = "pa\n",
	[PUSH_B] = "pb\n",
	[ROTATE_A] = "ra\n",
	[ROTATE_B] = "rb\n",
	[RROTATE_A] = "rra\n",
	[RROTATE_B] = "rrb\n",
	[SWAP_AB] = "ss\n",
	[ROTATE_AB] = "rr\n",
	[RROTATE_AB] = "rrr\n"
	};

	curr = ops;
	while (curr)
	{
		i = 0;
		while (move_str[curr->op][i])
			i++;
		write(1, move_str[curr->op], i);
		curr = curr->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_ops	*ops;
	int		i;

	if (argc < 2)
		return (1);
	if (argc > 2)
		parse_mul(&a, argc, argv);
	else
		parse_one(&a, argv[1]);
	if (!a)
		return (write(1, "Error\n", 6), 1);
	if (sort(&a, &b, &ops) && opti_ops(&ops))
		return (print_ops(ops), free_all(&a, &b, &ops), 0);
	return (write(1, "Error\n", 6), 1);
}
