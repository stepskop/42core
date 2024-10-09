/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:58:56 by username          #+#    #+#             */
/*   Updated: 2024/10/09 13:58:57 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	process_signal(int signo, siginfo_t *info, void *ctx)
{
	static unsigned int	curr_char;
	static int			bit_n;

	(void)ctx;
	curr_char = curr_char | (signo == SIGUSR1);
	bit_n++;
	if (bit_n == 8)
	{
		if (curr_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", curr_char);
		bit_n = 0;
		curr_char = 0;
	}
	else
		curr_char <<= 1;
	if (signo == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signo == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &process_signal;
	ft_printf("%i\n", (int)getpid());
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
