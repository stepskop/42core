/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:16:10 by username          #+#    #+#             */
/*   Updated: 2024/11/14 17:24:26 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	env_init(t_env *env)
{
	env->philo_count = 0;
	env->sim = 0;
	if (pthread_mutex_init(&env->sim_lock, NULL) != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	env;
	int		i;

	if (argc < 5 || argc > 6)
		return (printf("Number of arguments\n"), 1);
	if (!env_init(&env))
		return (printf("Init failed"), 1);
	if (!parse(argc, argv, &env))
		return (printf("Invalid parameters\n"), 1);
	i = -1;
	env.start_time = get_time(MICR_S);
	while (++i < env.philo_count)
		if (pthread_create(env.philo_arr[i]->thread, NULL,
				&routine, env.philo_arr[i]) != 0)
			return (free_env(&env), printf("Couldn't create thread\n"), 1);
	pthread_mutex_lock(&env.sim_lock);
	env.sim = 1;
	pthread_mutex_unlock(&env.sim_lock);
	i = -1;
	while (++i < env.philo_count)
		if (pthread_join(*(env.philo_arr[i]->thread), NULL) != 0)
			return (free_env(&env), printf("Couldn't join the thread\n"), 1);
	return (free_env(&env), 0);
}
