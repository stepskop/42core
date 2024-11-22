/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:02:42 by username          #+#    #+#             */
/*   Updated: 2024/11/22 15:36:01 by username         ###   ########.fr       */
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

static void	free_starr(char **starr)
{
	while (starr)
		free(*starr++);
	free(starr);
}

char	*get_cmd(char *cmd, char **env)
{
	char	*res;
	char	*path;
	char	**bin_dirs;
	char	*dir_slash;

	if (access(res, F_OK | X_OK) == 0)
		return (res);
	path = path_env(env);
	if (!path)
		return (NULL);
	bin_dirs = ft_split(path, ':');
	while (bin_dirs)
	{
		dir_slash = ft_strjoin(*bin_dirs, "/");
		if (!dir_slash)
			return (free_starr(bin_dirs), NULL);
		res = ft_strjoin(dir_slash, cmd);
		free(dir_slash);
		if (!res)
			return (free_starr(bin_dirs), NULL);
		if (access(res, F_OK | X_OK) == 0)
			return (free_starr(bin_dirs), res);
	}
	free_starr(bin_dirs);
	return (NULL);
}