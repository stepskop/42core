/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:22:41 by username          #+#    #+#             */
/*   Updated: 2024/11/19 14:55:14 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	stop_sim(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->env->philo_count)
		sem_post(philo->env->sim_sem);
}

int	health_check(t_philo *philo, time_t time_st)
{
	if (time_st > \
		(time_t)(philo->last_fed + 800 + (philo->attr.die_time * 1000)))
		return (0);
	return (1);
}

int	set_state(t_philo *philo, t_state new_state)
{
	time_t	time_st;
	time_t	start_tm;
	time_t	time_ms;

	time_st = get_time(MICR_S);
	start_tm = philo->env->start_time;
	time_ms = (time_st - start_tm) / 1000;
	if (!health_check(philo, time_st))
		new_state = DEAD;
	sem_wait(philo->env->print_sem);
	if (new_state == DREAM)
		printf("%ld %i is sleeping\n", time_ms, philo->id);
	else if (new_state == FORK)
		printf("%ld %i has taken a fork\n", time_ms, philo->id);
	else if (new_state == FEAST)
		printf("%ld %i is eating\n", time_ms, philo->id);
	else if (new_state == THINK)
		printf("%ld %i is thinking\n", time_ms, philo->id);
	else if (new_state == DEAD)
		return (printf("%ld %i died\n", time_ms, philo->id),
			stop_sim(philo), 0);
	sem_post(philo->env->print_sem);
	return (1);
}

static void	handle_single(t_philo *philo)
{
	set_state(philo, FORK);
	while (health_check(philo, get_time(MICR_S)))
		;
	sem_post(philo->env->sim_sem);
}

void	do_routine(t_philo *philo)
{
	philo->last_fed = get_time(MICR_S);
	if (philo->env->philo_count == 1)
		handle_single(philo);
	if (philo->id % 2)
		think(philo);
	while (1)
	{
		if (!feast(philo))
			break ;
		dream(philo);
		think(philo);
	}
}
