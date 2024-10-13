/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:13:35 by username          #+#    #+#             */
/*   Updated: 2024/10/14 01:46:48 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stk)
{
	t_stack	*curr;
	t_stack	*tmp;

	if (!stk)
		return ;
	curr = *stk;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*stk = NULL;
}

void	free_ops(t_ops **ops)
{
	t_ops	*curr;
	t_ops	*tmp;

	if (!ops)
		return ;
	curr = *ops;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*ops = NULL;
}

void	free_all(t_stack **a, t_stack **b, t_ops **ops)
{
	free_stack(a);
	free_stack(b);
	free_ops(ops);
}
