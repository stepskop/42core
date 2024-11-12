/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:22:55 by username          #+#    #+#             */
/*   Updated: 2024/11/12 20:43:50 by username         ###   ########.fr       */
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

static void	set_forks(t_philo **arr, int p_count)
{
	int	i;

	arr[p_count - 1]->fork_r = arr[0]->fork_l;
	i = -1;
	while (++i < (p_count - 1))
		arr[i]->fork_r = arr[i + 1]->fork_l;
}

static int	add_fork(t_philo *philo)
{
	pthread_mutex_t	*fork;

	fork = malloc(sizeof(pthread_mutex_t));
	if (!fork)
		return (0);
	pthread_mutex_init(fork, NULL);
	philo->fork_l = fork;
	return (1);
}

static int	add_philos(t_attr attr, t_env *env)
{
	int	i;
	t_philo	*curr;

	i = -1;
	while (++i < env->philo_count)
	{
		env->philo_arr[i] = malloc(sizeof(t_philo));
		curr = env->philo_arr[i];
		if (!curr)
			return (free_env(env), 0);
		curr->thread = malloc(sizeof(pthread_t));
		if (!curr->thread)
			return (free(curr),
			env->philo_arr[i] = NULL, free_env(env), 0);
		if (!add_fork(curr))
			return (free(curr), free(curr->thread),
			env->philo_arr[i] = NULL, free_env(env), 0);
		curr->attr = attr;
		curr->id = i + 1;
		curr->state = IDLIN;
		curr->curr_food = 0;
	}
	set_forks(env->philo_arr, env->philo_count);
	return (1);
}

int	parse(int argc, char **argv, t_env *env)
{
	t_attr	attr;

	env->philo_count = ft_atoi(argv[1]);
	attr = (t_attr){ft_atoi(argv[2]),
		ft_atoi(argv[3]), ft_atoi(argv[4]), -1};
	if (env->philo_count < 2 || attr.die_time < 1 ||
		attr.eat_time < 1 || attr.slp_time < 1)
		return (0);
	if (argc == 6)
	{
		attr.max_food = ft_atoi(argv[5]);
		if (attr.max_food < 1)
			return (0);
	}
	env->philo_arr = malloc(sizeof(t_philo) * env->philo_count);
	if (!env->philo_arr || !add_philos(attr, env))
		return (0);
	return (1);
}
