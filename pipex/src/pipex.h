/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:35:06 by username          #+#    #+#             */
/*   Updated: 2024/11/26 01:40:56 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_cmd
{
	char	*path;
	char	**args;
	int		pid;
	char	**full_cmd;
	char	**envp;
}	t_cmd;

// Utils
char	*get_cmd(char *cmd, char **env);
void	free_starr(char **starr);
int		cmd_init(char *cmd_str, t_cmd *cmd, char **envp);
void	free_cmd(t_cmd cmd);

#endif
