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

static int	from_proccess(t_cmd *from_cmd, int *pipefd, char *in_file)
{
	int	in_fd;

	in_fd = open(in_file, O_RDONLY, 0666);
	if (in_fd == -1)
		return (close(pipefd[1]), close(pipefd[0]), -1);
	from_cmd->pid = fork();
	if (from_cmd->pid == 0)
	{
		dup2(in_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		execve(from_cmd->path, from_cmd->full_cmd, from_cmd->envp);
	}
	close(in_fd);
	close(pipefd[1]);
	return (from_cmd->pid);
}

static int	to_process(t_cmd *to_cmd, int *pipefd, char *out_file)
{
	int	out_fd;

	out_fd = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (out_fd == -1)
		return (close(pipefd[0]), -1);
	to_cmd->pid = fork();
	if (to_cmd->pid == 0)
	{
		dup2(out_fd, STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		execve(to_cmd->path, to_cmd->full_cmd, to_cmd->envp);
	}
	close(out_fd);
	close(pipefd[0]);
	return (to_cmd->pid);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	from_cmd;
	t_cmd	to_cmd;
	int		pipefd[2];

	if (argc != 5)
		return (ft_printf("L BOZO\n"), 1);
	pipe(pipefd);
	if (!cmd_init(argv[2], &from_cmd, envp))
		return (ft_printf("Couldn't initialize cmd\n"), 1);
	if (from_proccess(&from_cmd, pipefd, argv[1]) == -1)
		return (free_cmd(from_cmd), ft_printf("Couldn't initialize cmd\n"), 0);
	waitpid(from_cmd.pid, NULL, 0);
	free_cmd(from_cmd);
	if (!cmd_init(argv[3], &to_cmd, envp))
		return (ft_printf("Couldn't initialize cmd\n"), 1);
	if (to_process(&to_cmd, pipefd, argv[4]) == -1)
		return (free_cmd(to_cmd), ft_printf("Couldn't initialize cmd\n"), 1);
	free_cmd(to_cmd);
}
