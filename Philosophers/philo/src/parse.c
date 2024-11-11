/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:22:55 by username          #+#    #+#             */
/*   Updated: 2024/11/11 15:41:23 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int     ft_atoi(const char *nptr)
{
        int     sign;
        int     res;
        int     i;

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

int	parse(int argc, char **argv, t_env *env)
{
	env->philo_count = ft_atoi(argv[1]);
	if (env->philo_count < 1)
		return (0);
	env->die_time = ft_atoi(argv[2]);
	if (env->die_time < 1)
		return (0);
	env->eat_time = ft_atoi(argv[3]);
	if (env->eat_time < 1)
		return (0);
	env->slp_time = ft_atoi(argv[4]);
	if (env->slp_time < 1)
		return (0);
	if (argc == 6)
	{
		env->max_food = ft_atoi(argv[5]);
		if (env->max_food < 1)
			return (0);
	}
	return (1);
}
