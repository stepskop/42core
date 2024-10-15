/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:35:32 by username          #+#    #+#             */
/*   Updated: 2024/10/14 02:06:19 by username         ###   ########.fr       */
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
		return (ft_putstr_fd("Error\n", 2), 1);
	parse_mul(&a, argc, argv);
	if (!a)
		return (ft_putstr_fd("Error\n", 2), free_all(&a, &b, &ops), 1);
	if (!sort(&a, &b, &ops))
		return (ft_putstr_fd("Error\n", 2), free_all(&a, &b, &ops), 1);
	return (print_ops(ops), free_all(&a, &b, &ops), 0);
}
