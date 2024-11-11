/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:16:10 by username          #+#    #+#             */
/*   Updated: 2024/11/11 15:48:52 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	env_init(t_env *env)
{
	env->die_time = -1;
	env->eat_time = -1;
	env->slp_time = -1;
	env->max_food = -1;
	env->philo_count = 0;
}

int	main(int argc, char **argv)
{
	t_env	env;
	if (argc < 5 || argc > 6)
		return (printf("Invalid parameters\n"), 1);
	env_init(&env);
	if (!parse(argc, argv, &env))
		return (printf("Invalid parameters\n"), 1);
	return (0);
}
