/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:11:15 by username          #+#    #+#             */
/*   Updated: 2024/10/10 22:45:32 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_stack **a, t_stack **b, t_ops **ops)
{
	if (is_sorted(*a))
		return (1);
	set_props(a, b);
	return (1);
}

int	sort_three(t_stack **stk, t_ops **ops)
{
	t_stack	*max;
}
