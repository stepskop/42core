/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:43:36 by username          #+#    #+#             */
/*   Updated: 2024/11/12 20:34:27 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_phil(t_philo **arr, int p_count)
{
	int	i;

	i = 0;
	while (i < p_count && arr[i])
	{
		pthread_mutex_destroy(arr[i]->fork_l);
		free(arr[i]->fork_l);
		free(arr[i]->thread);
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_env(t_env *env)
{
	free_phil(env->philo_arr, env->philo_count);
}
