/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:10:18 by username          #+#    #+#             */
/*   Updated: 2024/10/10 20:40:40 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	opti_ops(t_ops **ops)
{

}

int	add_op(t_ops **ops, enum e_moves move)
{
	t_ops	*new;
	t_ops	*i;
	int		index;

	new = malloc(1 * sizeof(t_stack));
	if (!new)
		return (0);
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
