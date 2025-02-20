/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:02:42 by username          #+#    #+#             */
/*   Updated: 2024/11/26 02:35:45 by username         ###   ########.fr       */
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

void	free_starr(char **starr)
{
	int	i;

	i = -1;
	if (!starr)
		return ;
	while (starr[++i])
		free(starr[i]);
	free(starr);
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

void	error_exit(t_err err, t_data data)
{
	if (err == INVALID_ARGS)
	{
		ft_putstr_fd("Invalid args\n", 2);
		exit (1);
	}
	else if (err == OPEN_ERR)
		perror("open");
	else if (err != OPEN_ERR)
	{
		close(data.out_file);
		if (!data.here_doc)
			close(data.in_file);
		perror(NULL);
		exit (1);
	}
}
