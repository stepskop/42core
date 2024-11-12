/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:16:10 by username          #+#    #+#             */
/*   Updated: 2024/11/12 20:39:00 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	env_init(t_env *env)
{
	env->philo_count = 0;
}

void	*routine(void *arg)
{
	t_philo	*p_arg;

	p_arg = (t_philo *)arg;
	printf("MIREK JE FRAJER %i\n", p_arg->id);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_env	env;
	int	i;

	if (argc < 5 || argc > 6)
		return (printf("Invalid parameters\n"), 1);
	env_init(&env);
	if (!parse(argc, argv, &env))
		return (printf("Invalid parameters\n"), 1);
	i = -1;
	while (++i < env.philo_count)
	{
		if (pthread_create(env.philo_arr[i]->thread, NULL, &routine, env.philo_arr[i]) != 0)
			return (free_env(&env), printf("RIP BOZO\n"), 1);
		pthread_detach(*(env.philo_arr[i]->thread));
	}
	pthread_exit(0);
	return (0);
}
