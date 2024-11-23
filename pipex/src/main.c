/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:34:54 by username          #+#    #+#             */
/*   Updated: 2024/11/22 14:43:43 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*parent_cmd;
	char	*child_cmd;
	int		parent_pid;
	int		child_pid;

	if (argc != 5)
		return (ft_printf("L BOZO\n"), 1);
	parent_cmd = get_cmd(argv[2], envp);
	parent_pid = fork();
	if (parent_pid == 0)
		execve(parent_cmd, argv + 1, envp);
	free(parent_cmd);
}
