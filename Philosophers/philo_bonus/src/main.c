/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:16:19 by username          #+#    #+#             */
/*   Updated: 2024/11/19 14:51:48 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	semaphore_init(t_env *env)
{
	sem_unlink("/sim");
	sem_unlink("/forks");
	sem_unlink("/print");
	env->sim_sem = sem_open("/sim", O_CREAT, 0600, 1);
	if (!env->sim_sem)
		return (0);
	env->forks_sem = sem_open("/forks", O_CREAT, 0600, env->philo_count);
	if (!env->forks_sem)
		return (sem_close(env->sim_sem), 0);
	env->print_sem = sem_open("/print", O_CREAT, 0600, 1);
	if (!env->print_sem)
		return (sem_close(env->sim_sem), sem_close(env->forks_sem), 0);
	return (1);
}

static void	*reaper_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	p_sleep(400);
	while (1)
	{
		if (!health_check(philo, get_time(MICR_S)))
		{
			set_state(philo, DEAD);
			break ;
		}
		p_sleep(10);
	}
	return (NULL);
}

static int	create_processes(t_env *env)
{
	int			i;
	pthread_t	reaper;

	i = -1;
	env->start_time = get_time(MICR_S);
	while (++i < env->philo_count)
	{
		env->philo_arr[i].pid = fork();
		if (env->philo_arr[i].pid == -1)
			return (0);
		if (env->philo_arr[i].pid == 0)
		{
			if (pthread_create(&reaper, NULL,
					&reaper_routine, &env->philo_arr[i]) != 0)
				return (0);
			do_routine(&env->philo_arr[i]);
			exit(0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	env;
	int		i;

	if (argc < 5 || argc > 6)
		return (printf("Number of arguments\n"), 1);
	env.philo_count = 0;
	if (!parse(argc, argv, &env))
		return (printf("Error while parsing\n"), 1);
	if (!semaphore_init(&env))
		return (printf("Error while semaphore init\n"), free(env.philo_arr), 1);
	sem_wait(env.sim_sem);
	if (!create_processes(&env))
		return (free_env(&env), printf("Error while starting sim\n"), 1);
	i = -1;
	while (++i < env.philo_count)
		sem_wait(env.sim_sem);
	return (free_env(&env), 0);
}
