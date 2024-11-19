/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:45:30 by username          #+#    #+#             */
/*   Updated: 2024/11/19 15:27:23 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	t_attr	attr;
	time_t	think_time;

	if (!set_state(philo, THINK))
		exit (0);
	attr = philo->attr;
	think_time = attr.eat_time * 2 - attr.slp_time;
	if (!(philo->env->philo_count % 2))
		return ;
	p_sleep(1000 * (think_time * 0.5), philo);
}

void	dream(t_philo *philo)
{
	if (!set_state(philo, DREAM))
		exit (0);
	p_sleep(philo->attr.slp_time * 1000, philo);
}

int	feast(t_philo *philo)
{
	sem_wait(philo->env->forks_sem);
	set_state(philo, FORK);
	sem_wait(philo->env->forks_sem);
	set_state(philo, FORK);
	set_state(philo, FEAST);
	philo->last_fed = get_time(MICR_S);
	philo->curr_food++;
	p_sleep(philo->attr.eat_time * 1000, philo);
	sem_post(philo->env->forks_sem);
	sem_post(philo->env->forks_sem);
	if (philo->curr_food == philo->attr.max_food)
		return (sem_post(philo->env->sim_sem), 0);
	return (1);
}
