/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:19:02 by username          #+#    #+#             */
/*   Updated: 2024/11/14 17:23:51 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_state(t_philo *philo, t_state new_state)
{
	if (!get_simstate(philo))
		return ;
	if (new_state != DEAD)
	{
		if (get_time() > (time_t)(philo->last_fed + philo->attr.die_time))
		{
			set_state(philo, DEAD);
			pthread_mutex_lock(&philo->env->sim_lock);
			philo->env->sim = 0;
			pthread_mutex_unlock(&philo->env->sim_lock);
			return ;
		}
	}
	pthread_mutex_lock(&(philo->env->print_lock));
	philo->state = new_state;
	if (new_state == DREAM)
		printf("%ld %i is sleeping\n", get_time() - philo->env->start_time, philo->id);
	else if (new_state == FORK_R)
		printf("%ld %i has taken a fork\n", get_time() - philo->env->start_time, philo->id);
	else if (new_state == FORK_L)
		printf("%ld %i has taken a fork\n", get_time() - philo->env->start_time, philo->id);
	else if (new_state == FEAST)
		printf("%ld %i is eating\n", get_time() - philo->env->start_time, philo->id);
	else if (new_state == THINK)
		printf("%ld %i is thinking\n", get_time() - philo->env->start_time, philo->id);
	else if (new_state == DEAD)
	{
		printf("%ld %i died\n", get_time() - philo->env->start_time, philo->id);
	}
	pthread_mutex_unlock(&(philo->env->print_lock));
}

int	get_simstate(t_philo *philo)
{
	int	res;

	res = 0;
	pthread_mutex_lock(&philo->env->sim_lock);
	if (philo->env->sim)
		res = 1;
	pthread_mutex_unlock(&philo->env->sim_lock);
	return (res);
}

void	*routine(void *arg)
{
	t_philo	*p_arg;

	p_arg = (t_philo *)arg;
	while (!get_simstate(p_arg))
		usleep(1); // HELGRIND
	p_arg->last_fed = get_time();
	while (get_simstate(p_arg))
	{
		feast(p_arg);
		dream(p_arg);
	}
	return (NULL);
}
