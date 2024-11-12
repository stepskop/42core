/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:16:26 by username          #+#    #+#             */
/*   Updated: 2024/11/12 20:33:37 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef enum	e_fork
{
	FORK_R,
	FORK_L
}	t_fork;

typedef enum	e_state
{
	IDLIN,
	FEAST,
	DREAM,
	THINK
}	t_state;

typedef struct	s_attr
{
	size_t	die_time;
	size_t	eat_time;
	size_t	slp_time;
	size_t	max_food;
}	t_attr;

typedef struct	s_philo
{
	int	id;
	t_state	state;
	size_t	curr_food;
	t_attr	attr;
	pthread_t	*thread;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
}	t_philo;

typedef struct	s_env
{
	int	philo_count;
	t_philo	**philo_arr;
}	t_env;

// Parse
int	parse(int argc, char **argv, t_env *env);

// Memory
void	free_env(t_env *env);

#endif
