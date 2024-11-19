/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:03:15 by username          #+#    #+#             */
/*   Updated: 2024/11/19 14:20:40 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H 
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

typedef enum e_state
{
	FORK,
	FEAST,
	DREAM,
	THINK,
	DEAD
}	t_state;

typedef enum e_unit
{
	MICR_S,
	MILI_S
}	t_unit;

typedef struct s_attr
{
	int	die_time;
	int	eat_time;
	int	slp_time;
	int	max_food;
}	t_attr;

typedef struct s_philo
{
	int				id;
	int				pid;
	t_attr			attr;
	int				curr_food;
	time_t			last_fed;
	struct s_env	*env;
}	t_philo;

typedef struct s_env
{
	int		philo_count;
	t_philo	*philo_arr;
	time_t	start_time;
	sem_t	*sim_sem;
	sem_t	*print_sem;
	sem_t	*forks_sem;
}	t_env;

// Parse
int		parse(int argc, char **argv, t_env *env);

// Memory
void	free_env(t_env *env);

// Actions
void	think(t_philo *philo);
void	dream(t_philo *philo);
int		feast(t_philo *philo);

// Time
void	p_sleep(time_t usec);
time_t	get_time(t_unit unit);

// Routine
void	do_routine(t_philo *philo);
int		set_state(t_philo *philo, t_state new_state);
#endif
