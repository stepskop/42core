/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:58:55 by username          #+#    #+#             */
/*   Updated: 2024/11/25 13:30:26 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef enum e_err
{
	NOT_FOUND,
	MALLOC_ERR,
	PROC_ERR,
	OPEN_ERR,
	INVALID_ARGS,
	PIPE_ERR
}	t_err;

typedef struct s_cmd
{
	char	*path;
	char	**cmd_line;
	int		pid;
	char	**envp;
}	t_cmd;

typedef struct s_data
{
	int		in_file;
	int		out_file;
	int		cmd_count;
	int		here_doc;
	char	**envp;
}	t_data;

//Utils
void	free_starr(char **starr);
char	*get_cmd(char *cmd, char **env);

//Parse
int		parse(int argc, char **argv, t_data *data);
t_cmd	parse_cmd(t_data data, char *cmd_str);
void	error_exit(t_err err, t_data data);

#endif
