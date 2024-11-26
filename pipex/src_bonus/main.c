/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:57:10 by username          #+#    #+#             */
/*   Updated: 2024/11/26 01:18:49 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec(char *cmd_str, t_data data)
{
	t_cmd	cmd;

	cmd = parse_cmd(data, cmd_str);
	execve(cmd.path, cmd.cmd_line, data.envp);
}

static void	pipeline(t_data data, char *cmd_str)
{
	int	pipefd[2];
	int	pid;

	if (pipe(pipefd) == -1)
		error_exit(PIPE_ERR, data);
	pid = fork();
	if (pid == -1)
		error_exit(PROC_ERR, data);
	else if (pid == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		exec(cmd_str, data);
	}
	else
	{
		waitpid(pid, NULL, 0);
		dup2(pipefd[0], STDIN_FILENO);
	}
	close(pipefd[1]);
	close(pipefd[0]);
}

static void	read_stdin(int *pipefd, char *limiter)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(line, limiter, ft_strlen(limiter)))
		{
			free(line);
			exit (0);
		}
		ft_putstr_fd(line, pipefd[1]);
		free(line);
	}
}

static void	here_doc(char *limiter, t_data data)
{
	int		pipefd[2];
	int		pid;

	if (pipe(pipefd) == -1)
		error_exit(PIPE_ERR, data);
	pid = fork();
	if (pid == -1)
		error_exit(PROC_ERR, data);
	if (pid == 0)
		read_stdin(pipefd, limiter);
	else
	{
		wait(NULL);
		dup2(pipefd[0], 0);
	}
	close(pipefd[1]);
	close(pipefd[0]);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		last_pid;
	int		i;

	data.envp = envp;
	parse(argc, argv, &data);
	if (data.here_doc)
		here_doc(argv[2], data);
	else
		dup2(data.in_file, STDIN_FILENO);
	data.cmd_count = argc - 3 - data.here_doc;
	i = -1;
	while (++i < data.cmd_count)
		pipeline(data, argv[2 + data.here_doc + i]);
	dup2(data.out_file, STDOUT_FILENO);
	last_pid = fork();
	if (last_pid == 0)
		exec(argv[argc - 2], data);
	if (!data.here_doc)
		close(data.in_file);
	close(data.out_file);
	return (0);
}
