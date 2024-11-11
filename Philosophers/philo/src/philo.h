/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:16:26 by username          #+#    #+#             */
/*   Updated: 2024/11/11 15:41:37 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct	s_env
{
	int	philo_count;
	int	die_time;
	int	eat_time;
	int	slp_time;
	int	max_food;
}	t_env;

int	parse(int argc, char **argv, t_env *env);

#endif
