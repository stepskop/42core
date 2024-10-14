/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:27:57 by username          #+#    #+#             */
/*   Updated: 2024/10/14 00:59:33 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_num(char *str, int *value)
{
	int	sign;
	int	i;
	int	digit;

	i = 0;
	sign = 1;
	*value = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - 48;
		if (*value > (INT_MAX - digit) / 10)
			return (0);
		*value = (*value * 10) + str[i++] - 48;
	}
	*value *= sign;
	return (1);
}

int	is_valid(char *str, int *value, int parse_one)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (parse_one && ft_isspace(str[i]))
			break ;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	i = -1;
	if (!get_num(str, value))
		return (0);
	return (1);
}

static int	is_duplicate(t_stack **stk, int value)
{
	t_stack	*curr;

	curr = *stk;
	while (curr)
	{
		if (curr->value == value)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	add_new(t_stack **stk, int value, enum e_stacks stk_e)
{
	t_stack	*new;
	t_stack	*i;

	if (is_duplicate(stk, value))
		return (0);
	new = malloc(1 * sizeof(t_stack));
	if (!new)
		return (0);
	new->index = 0;
	new->cheap = 0;
	new->stk_e = stk_e;
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	if (!*stk)
		return (*stk = new, 1);
	i = *stk;
	while (i->next)
		i = i->next;
	new->index = i->index + 1;
	i->next = new;
	new->prev = i;
	return (1);
}
