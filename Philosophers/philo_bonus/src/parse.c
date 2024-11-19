/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:30:58 by username          #+#    #+#             */
/*   Updated: 2024/11/19 14:16:43 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + nptr[i] - 48;
		i++;
	}
	return (sign * res);
}

static void	add_philos(t_attr attr, t_env *env)
{
	int		i;

	i = -1;
	while (++i < env->philo_count)
	{
		env->philo_arr[i].attr = attr;
		env->philo_arr[i].id = i + 1;
		env->philo_arr[i].curr_food = 0;
		env->philo_arr[i].env = env;
	}
}

int	parse(int argc, char **argv, t_env *env)
{
	t_attr	attr;

	env->philo_count = ft_atoi(argv[1]);
	attr = (t_attr){ft_atoi(argv[2]),
		ft_atoi(argv[3]), ft_atoi(argv[4]), -1};
	if (env->philo_count < 1 || attr.die_time < 1 || \
		attr.eat_time < 1 || attr.slp_time < 1)
		return (0);
	if (argc == 6)
	{
		attr.max_food = ft_atoi(argv[5]);
		if (attr.max_food < 1)
			return (0);
	}
	env->philo_arr = malloc(sizeof(t_philo) * env->philo_count);
	if (!env->philo_arr)
		return (0);
	add_philos(attr, env);
	return (1);
}
