/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:06:53 by username          #+#    #+#             */
/*   Updated: 2024/10/14 00:54:20 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_format(char *str)
{
	int			i;
	const char	*moves[] = {
		"pa", "pb", "sa", "sb", "ra", "rb", "rra", "rrb", "ss", "rr", "rrr"};

	i = -1;
	while (++i < 11)
	{
		if (!ft_strncmp(str, moves[i], ft_strlen(moves[i])))
			return (i);
	}
	return (-1);
}

void	use_move(int op, t_stack **a, t_stack **b)
{
	if (op == PUSH_A)
		push((t_push){b, a}, NULL);
	if (op == PUSH_B)
		push((t_push){a, b}, NULL);
	if (op == SWAP_A || op == SWAP_AB)
		swap(a, NULL);
	if (op == SWAP_B || op == SWAP_AB)
		swap(b, NULL);
	if (op == ROTATE_A || op == ROTATE_AB)
		rotate(a, NULL);
	if (op == ROTATE_B || op == ROTATE_AB)
		rotate(b, NULL);
	if (op == RROTATE_A || op == RROTATE_AB)
		rrotate(a, NULL);
	if (op == RROTATE_B || op == RROTATE_AB)
		rrotate(b, NULL);
}

static int	check(t_stack **a, t_stack **b)
{
	int		op_i;
	char	*read_op;

	read_op = get_next_line(0);
	while (read_op)
	{
		op_i = check_format(read_op);
		if (op_i == -1)
			return (free(read_op), 0);
		use_move(op_i, a, b);
		free(read_op);
		read_op = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (write(2, "Error\n", 6), 1);
	if (argc > 2)
		parse_mul(&a, argc, argv);
	else
		parse_one(&a, argv[1]);
	if (!a || !check(&a, &b))
		return (write(2, "Error\n", 6), free_all(&a, &b, NULL), 1);
	if (is_sorted(a) && !b)
		return (write(1, "OK\n", 3), free_all(&a, &b, NULL), 0);
	return (write(1, "KO\n", 2), free_all(&a, &b, NULL), 1);
}
