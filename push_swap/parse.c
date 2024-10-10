/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:08:52 by username          #+#    #+#             */
/*   Updated: 2024/10/10 19:52:47 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_mul(t_stack **a, int argc, char **argv)
{
	int		i;
	int		value;
	int		*all_nums;

	value = 0;
	all_nums = malloc((argc - 1) * sizeof(int));
	if (!all_nums)
		return ;
	i = 1;
	while (argv[i])
	{
		if (!is_valid(argv[i], &value, all_nums, argc - 1))
			return (free_stack(a), free(all_nums));
		if (!add_new(a, value))
			return (free_stack(a), free(all_nums));
		i++;
	}
	free(all_nums);
}

void	parse_one(t_stack **a, char *str)
{
	int		*all_nums;
	int		i;
	int		value;
	size_t	wcount;

	value = 1;
	wcount = count_words(str);
	all_nums = malloc(wcount * sizeof(int));
	if (!all_nums)
		return ;
	i = -1;
	while (str[++i])
	{
		if (!ft_isspace(str[i]))
		{
			if (!is_valid(&(str[i]), &value, all_nums, wcount))
				return (free_stack(a), free(all_nums));
			if (!add_new(a, value))
				return (free_stack(a), free(all_nums));
			while (!ft_isspace(str[i]) && str[i])
				i++;
			continue ;
		}
	}
	free(all_nums);
}
