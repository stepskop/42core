/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:14:29 by username          #+#    #+#             */
/*   Updated: 2024/11/14 17:21:09 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	pick_fork(t_fork fork_e, t_philo *philo)
{
	*(philo->forks[fork_e].stat) = philo->id;
	if (fork_e == L)
		set_state(philo, FORK_L);
	else
		set_state(philo, FORK_R);
}

void	think(t_philo *philo)
{
	time_t	think_time;
	t_attr	attr;

	set_state(philo, THINK);
	attr = philo->attr;
	think_time = attr.eat_time * 2 - attr.slp_time;
	if (!(philo->env->philo_count % 2))
		return ;
	p_sleep(1000 * (think_time * 0.5), philo);
}

int	feast(t_philo *philo)
{
	t_fork	fir;
	t_fork	sec;

	fir = L;
	sec = R;
	if (philo->id % 2)
	{
		fir = R;
		sec = L;
	}
	pthread_mutex_lock(philo->forks[fir].mutx);
	pick_fork(fir, philo);
	pthread_mutex_lock(philo->forks[sec].mutx);
	pick_fork(sec, philo);
	philo->last_fed = get_time(MILI_S);
	set_state(philo, FEAST);
	philo->curr_food += 1;
	p_sleep((philo->attr.eat_time * 1000), philo);
	pthread_mutex_unlock(philo->forks[fir].mutx);
	pthread_mutex_unlock(philo->forks[sec].mutx);
	if (philo->curr_food == philo->attr.max_food)
		return (0);
	return (1);
}

void	dream(t_philo *philo)
{
	set_state(philo, DREAM);
	p_sleep((philo->attr.slp_time * 1000), philo);
}
