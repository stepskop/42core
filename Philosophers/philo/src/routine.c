/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:19:02 by username          #+#    #+#             */
/*   Updated: 2024/11/11 15:19:56 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_state(t_philo *philo, t_state new_state)
{
	philo->state = new_state;
	if (new_state == DREAM)
		printf("%i is sleeping\n", philo->id);
	else if (new_state == FORK_R)
		printf("%i has taken R fork\n", philo->id);
	else if (new_state == FORK_L)
		printf("%i has taken L fork\n", philo->id);
	else if (new_state == FEAST)
		printf("%i is eating\n", philo->id);
	else if (new_state == THINK)
		printf("%i is thinking\n", philo->id);
}

void	*routine(void *arg)
{
	t_philo	*p_arg;

	p_arg = (t_philo *)arg;
	while (!p_arg->env->sim)
		;
	if (p_arg->id % 2 == 0)
		think(p_arg);
	while (p_arg->env->sim)
	{
		feast(p_arg);
		dream(p_arg);
	}
	return (NULL);
}
