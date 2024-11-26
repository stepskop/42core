/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:02:42 by username          #+#    #+#             */
/*   Updated: 2024/11/26 02:13:18 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*path_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (ft_strchr(env[i], '=') + 1);
	}
	return (NULL);
}

int	cmd_init(char *cmd_str, t_cmd *cmd, char **envp)
{
	cmd->full_cmd = ft_split(cmd_str, ' ');
	if (!cmd->full_cmd)
		return (0);
	if (cmd->full_cmd[0][0] == '/')
		cmd->path = ft_strdup(cmd->full_cmd[0]);
	else
		cmd->path = get_cmd(cmd->full_cmd[0], envp);
	if (!cmd->path)
		return (free_starr(cmd->full_cmd), 0);
	cmd->pid = 0;
	return (1);
}

char	*get_cmd(char *cmd, char **env)
{
	char	*res;
	char	*path;
	char	**bin_dirs;
	char	*dir_slash;
	int		i;

	path = path_env(env);
	if (!path)
		return (NULL);
	bin_dirs = ft_split(path, ':');
	i = -1;
	while (bin_dirs[++i])
	{
		dir_slash = ft_strjoin(bin_dirs[i], "/");
		if (!dir_slash)
			return (free_starr(bin_dirs), NULL);
		res = ft_strjoin(dir_slash, cmd);
		free(dir_slash);
		if (!res)
			return (free_starr(bin_dirs), NULL);
		if (access(res, F_OK | X_OK) == 0)
			return (free_starr(bin_dirs), res);
		free(res);
	}
	return (free_starr(bin_dirs), NULL);
}

void	free_starr(char **starr)
{
	int	i;

	i = -1;
	while (starr[++i])
		free(starr[i]);
	free(starr);
}

void	free_cmd(t_cmd cmd)
{
	free(cmd.path);
	free_starr(cmd.full_cmd);
}
