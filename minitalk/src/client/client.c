/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:58:47 by username          #+#    #+#             */
/*   Updated: 2024/10/09 13:58:48 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	ack(int signo)
{
	if (signo == SIGUSR1)
		ft_printf("Recieved 1\n");
	else if (signo == SIGUSR2)
		ft_printf("Recieved 0\n");
}

static void	send_char(int pid, char c)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if ((c >> i) % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
	}
}

int	main(int argc, char **argv)
{
	char	*msg;
	int		pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid < 0 || pid > MAX_PID)
		return (ft_printf("Invalid PID\n"), 1);
	signal(SIGUSR1, ack);
	signal(SIGUSR2, ack);
	msg = argv[2];
	while (*msg)
		send_char(pid, *msg++);
	send_char(pid, '\0');
	return (0);
}
