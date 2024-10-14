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

void	parse_mul(t_stack **a, int argc, char **argv)
{
	int		i;
	int		value;

	value = 0;
	i = 1;
	while (i < argc)
	{
		if (!is_valid(argv[i], &value, 0) \
		|| !add_new(a, value, A))
		{
			free_stack(a);
			return ;
		}
		i++;
	}
}

void	parse_one(t_stack **a, char *str)
{
	int		i;
	int		value;

	value = 0;
	i = -1;
	while (str[++i])
	{
		if (!ft_isspace(str[i]))
		{
			if (!is_valid(&(str[i]), &value, 1) \
			|| !add_new(a, value, A))
			{
				free_stack(a);
				return ;
			}
			while (!ft_isspace(str[i]) && str[i])
				i++;
			if (str[i])
				continue ;
			else
				break ;
		}
	}
}
