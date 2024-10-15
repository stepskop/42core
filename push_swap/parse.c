/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:08:52 by username          #+#    #+#             */
/*   Updated: 2024/10/11 19:21:42 by username         ###   ########.fr       */
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

void	parse_mul(t_stack **a, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
		if (!parse_one(a, argv[i++]))
			return ;
}
