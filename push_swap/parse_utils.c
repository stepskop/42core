/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:27:57 by username          #+#    #+#             */
/*   Updated: 2024/10/10 21:08:00 by username         ###   ########.fr       */
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
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - 48;
		if (*value > (INT_MAX - digit) / 10)
			return (0);
		*value = (*value * 10) + str[i] - 48;
		i++;
	}
	return (1);
}

size_t	count_words(char *str)
{
	int		i;
	size_t	wcount;

	i = 0;
	wcount = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]) && (ft_isspace(str[i + 1]) || !str[i + 1]))
			wcount++;
		i++;
	}
	return (wcount);
}

int	is_valid(char *str, int *value, int *all_nums, int num_count)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (*value && ft_isspace(str[i]))
			break ;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	i = 0;
	if (!get_num(str, value))
		return (0);
	while (i < num_count)
	{
		if (all_nums[i++] == *value)
			return (0);
	}
	all_nums[i] = *value;
	return (1);
}

int	add_new(t_stack **stk, int value)
{
	t_stack	*new;
	t_stack	*i;
	int		index;

	new = malloc(1 * sizeof(t_stack));
	if (!new)
		return (0);
	new->index = 0;
	new->cheap = 0;
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	if (!*stk)
		*stk = new;
	else
	{
		i = *stk;
		while (i->next)
			i = i->next;
		new->index = i->index + 1;
		i->next = new;
		new->prev = i;
	}
	return (1);
}
