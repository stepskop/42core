/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:34:54 by username          #+#    #+#             */
/*   Updated: 2024/11/26 02:27:05 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

static int	from_proccess(t_cmd *f_cmd, int *pipefd, char *in_file, char **argv)
{
	int	in_fd;

	in_fd = open(in_file, O_RDONLY, 0666);
	if (in_fd == -1)
		return (perror("open"), close(pipefd[1]), close(pipefd[0]), -1);
	f_cmd->pid = fork();
	if (f_cmd->pid == -1)
		return (perror("fork"), -1);
	if (f_cmd->pid == 0)
	{
		if (!cmd_init(argv[2], f_cmd, f_cmd->envp))
			return (write(2, "Command not found\n", 19), exit(1), -1);
		dup2(in_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		execve(f_cmd->path, f_cmd->full_cmd, f_cmd->envp);
	}
	close(in_fd);
	close(pipefd[1]);
	return (f_cmd->pid);
}

static int	to_process(t_cmd *t_cmd, int *pipefd, char *out_file, char **argv)
{
	int	out_fd;

	out_fd = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (out_fd == -1)
		return (perror("open"), close(pipefd[0]), -1);
	t_cmd->pid = fork();
	if (t_cmd->pid == -1)
		return (perror("fork"), -1);
	if (t_cmd->pid == 0)
	{
		if (!cmd_init(argv[3], t_cmd, t_cmd->envp))
			return (write(2, "Command not found\n", 19), exit(1), -1);
		dup2(out_fd, STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		execve(t_cmd->path, t_cmd->full_cmd, t_cmd->envp);
	}
	close(out_fd);
	close(pipefd[0]);
	return (t_cmd->pid);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	f_cmd;
	t_cmd	t_cmd;
	int		pipefd[2];

	if (argc != 5)
		return (ft_putstr_fd("Invalid args\n", 2), 1);
	if (pipe(pipefd) == -1)
		return (perror("fork"), -1);
	f_cmd.envp = envp;
	if (from_proccess(&f_cmd, pipefd, argv[1], argv) == -1)
		return (1);
	waitpid(f_cmd.pid, NULL, 0);
	t_cmd.envp = envp;
	if (to_process(&t_cmd, pipefd, argv[4], argv) == -1)
		return (1);
}
