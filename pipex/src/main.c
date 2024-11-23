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
#include <unistd.h>

static void	free_cmd(t_cmd cmd)
{
	free(cmd.path);
	free_starr(cmd.full_cmd);
}

static int	cmd_init(char *cmd_str, t_cmd *cmd, char **envp)
{
	cmd->full_cmd = ft_split(cmd_str, ' ');
	if (!cmd->full_cmd)
		return (0);
	cmd->path = get_cmd(cmd->full_cmd[0], envp);
	if (!cmd->path)
		return (0);
	cmd->pid = 0;
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	prnt_cmd;
	t_cmd	chld_cmd;
	int		pipefd[2];

	if (argc != 3)
		return (ft_printf("L BOZO\n"), 1);
	if (!cmd_init(argv[1], &prnt_cmd, envp))
		return (ft_printf("Couldn't initialize cmd\n"), 1);
	if (!cmd_init(argv[2], &chld_cmd, envp))
		return (free_cmd(prnt_cmd), ft_printf("Couldn't initialize cmd\n"), 1);
	pipe(pipefd);
	prnt_cmd.pid = fork();
	if (prnt_cmd.pid == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		execve(prnt_cmd.path, prnt_cmd.full_cmd, envp);
	}
	waitpid(prnt_cmd.pid, NULL, 0);
	chld_cmd.pid = fork();
	if (chld_cmd.pid == 0)
	{
		dup2(STDIN_FILENO, pipefd[0]);
		execve(chld_cmd.path, chld_cmd.full_cmd, envp);
	}
	free_cmd(chld_cmd);
	free_cmd(prnt_cmd);
}
