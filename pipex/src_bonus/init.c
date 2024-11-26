/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:22:53 by username          #+#    #+#             */
/*   Updated: 2024/11/26 02:30:58 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**parse_cmdline(char *cmd_str)
{
	char	**res;

	res = ft_split(cmd_str, ' ');
	return (res);
}

t_cmd	parse_cmd(t_data data, char *cmd_str)
{
	t_cmd	cmd;

	cmd.cmd_line = parse_cmdline(cmd_str);
	if (!cmd.cmd_line)
		error_exit(MALLOC_ERR, data);
	cmd.path = get_cmd(cmd.cmd_line[0], data.envp);
	if (!cmd.path)
	{
		free_starr(cmd.cmd_line);
		error_exit(NOT_FOUND, data);
	}
	cmd.pid = 0;
	return (cmd);
}

int	parse(int argc, char **argv, t_data *data)
{
	int	out_flag;

	out_flag = O_APPEND;
	data->here_doc = 0;
	if (argc < 5)
		error_exit(INVALID_ARGS, *data);
	if (!ft_strcmp(argv[1], "here_doc"))
		data->here_doc = 1;
	if (data->here_doc && argc < 6)
		error_exit(INVALID_ARGS, *data);
	if (!data->here_doc)
	{
		out_flag = O_TRUNC;
		data->in_file = open(argv[1], O_RDONLY, 0666);
		if (data->in_file == -1)
			return (error_exit(OPEN_ERR, *data), exit (1), 1);
	}
	data->out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | out_flag, 0666);
	if (data->out_file == -1)
		return (close(data->in_file), error_exit(OPEN_ERR, *data), exit(1), 1);
	return (1);
}
