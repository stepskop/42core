/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:39:07 by username          #+#    #+#             */
/*   Updated: 2024/11/14 17:22:54 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time(t_unit unit)
{
	struct timeval	time;
	time_t			res;

	gettimeofday(&time, NULL);
	if (unit == MILI_S)
		res = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	else
		res = (time.tv_sec * 1000000) + time.tv_usec;
	return (res);
}

void	p_sleep(time_t usec, t_philo *philo)
{
	time_t	start;
	time_t	elapsed;
	time_t	remaining;

	start = get_time(MICR_S);
	while (get_time(MICR_S) - start < usec)
	{
		if (!get_simstate(philo))
			break ;
		elapsed = get_time(MICR_S) - start;
		remaining = usec - elapsed;
		if (remaining > 1e3)
			usleep(remaining / 2);
		else
			while (get_time(MICR_S) - start < usec)
				;
	}
}
