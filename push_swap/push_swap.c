/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:35:32 by username          #+#    #+#             */
/*   Updated: 2024/10/12 02:37:01 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (print_ops(ops), free_all(&a, &b, &ops), 0);
	return (write(2, "Error\n", 6), 1);
}
