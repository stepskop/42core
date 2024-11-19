/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:11:48 by username          #+#    #+#             */
/*   Updated: 2024/11/19 14:10:54 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_env(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->philo_count)
		if (env->philo_arr[i].pid > 0)
			kill(env->philo_arr[i].pid, SIGKILL);
	sem_close(env->forks_sem);
	sem_close(env->sim_sem);
	sem_close(env->print_sem);
	free(env->philo_arr);
}
