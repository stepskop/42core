/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:16:26 by username          #+#    #+#             */
/*   Updated: 2024/11/14 17:24:05 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef enum e_unit
{
	MICR_S,
	MILI_S
}	t_unit;

typedef enum e_fork
{
	L,
	R
}	t_fork;

typedef enum e_state
{
	IDLIN,
	FORK_R,
	FORK_L,
	FEAST,
	DREAM,
	THINK,
	DEAD,
}	t_state;

typedef struct s_attr
{
	int	die_time;
	int	eat_time;
	int	slp_time;
	int	max_food;
}	t_attr;

typedef struct s_fork_data
{
	pthread_mutex_t	*mutx;
	int				*stat;
}	t_fork_data;

typedef struct s_philo
{
	int				id;
	t_state			state;
	time_t			last_fed;
	int				curr_food;
	t_attr			attr;
	t_fork_data		forks[2];
	pthread_t		*thread;
	struct s_env	*env;
}	t_philo;

typedef struct s_env
{
	int				philo_count;
	int				sim;
	unsigned long	start_time;
	t_philo			**philo_arr;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	sim_lock;
}	t_env;

// Parse
int		parse(int argc, char **argv, t_env *env);

// Thread utils
int		get_simstate(t_philo *philo);

// Time
time_t	get_time(t_unit unit);
void	p_sleep(time_t usec, t_philo *philo);

// Memory
void	free_env(t_env *env);

// Routine
void	*routine(void *arg);
int		set_state(t_philo *philo, t_state new_state);
int		feast(t_philo *philo);
void	dream(t_philo *philo);
void	think(t_philo *philo);

#endif
