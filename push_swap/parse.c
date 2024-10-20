/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:08:52 by username          #+#    #+#             */
/*   Updated: 2024/10/20 18:57:54 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_one(t_stack **a, char *str)
{
	int		i;
	int		value;

	value = 0;
	i = -1;
	while (str[++i])
	{
		if (!ft_isspace(str[i]))
		{
			if (!is_valid(&(str[i]), &value) \
			|| !add_new(a, value, A))
				return (free_stack(a), 0);
			while (!ft_isspace(str[i]) && str[i])
				i++;
			if (str[i])
				continue ;
			else
				break ;
		}
	}
	return (1);
}

int	parse_mul(t_stack **a, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
		if (!parse_one(a, argv[i++]))
			return (0);
	return (1);
}
