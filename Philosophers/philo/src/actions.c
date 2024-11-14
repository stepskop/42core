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

static void	place_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->forks[R].mutx);
	*(philo->forks[R].stat) = 0;
	pthread_mutex_unlock(philo->forks[R].mutx);
	pthread_mutex_lock(philo->forks[L].mutx);
	*(philo->forks[L].stat) = 0;
	pthread_mutex_unlock(philo->forks[L].mutx);
}

void	think(t_philo *philo)
{
	if (!get_simstate(philo))
		return ;
	if (philo->state != THINK)
		set_state(philo, THINK);
}

void	feast(t_philo *philo)
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
	if (!get_simstate(philo))
		return ;
	while (get_simstate(philo))
	{
		usleep(1);
		if ((philo->id % 2 && philo->state != FORK_R) || (!(philo->id % 2) && philo->state != FORK_L))
		{
			pthread_mutex_lock(philo->forks[fir].mutx);
			if (!*(philo->forks[fir].stat))
				pick_fork(fir, philo);
			else
				think(philo);
			pthread_mutex_unlock(philo->forks[fir].mutx);
		}
		if (philo->state == THINK)
			continue;
		pthread_mutex_lock(philo->forks[sec].mutx);
		if (!*(philo->forks[sec].stat))
			pick_fork(sec, philo);
		pthread_mutex_unlock(philo->forks[sec].mutx);
		if ((philo->id % 2 && philo->state == FORK_L) || (!(philo->id % 2) && philo->state == FORK_R))
			break;
	}
	if (!get_simstate(philo))
		return ;
	set_state(philo, FEAST);
	philo->last_fed = get_time();
	philo->curr_food += 1;
	usleep(1000 * philo->attr.eat_time);
	place_forks(philo);
	if (philo->curr_food == philo->attr.max_food)
		pthread_exit(0);
}

void	dream(t_philo *philo)
{
	if (!get_simstate(philo))
		return ;
	set_state(philo, DREAM);
	usleep(1000 * philo->attr.slp_time);
}
