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

typedef enum e_err
{
	NOT_FOUND,
	MALLOC_ERR,
	PROC_ERR,
	OPEN_ERR,
}	t_err;

typedef struct s_cmd
{
	char	*path;
	char	**cmd_line;
}	t_cmd;

typedef struct s_data
{
	int		in_file;
	int		out_file;
	t_cmd	*cmd_arr;
}	t_data;

//Utils
void	free_starr(char **starr);
char	*get_cmd(char *cmd, char **env);

//Parse
int		parse(int argc, char **argv, char **envp, t_data *data);
void	error(t_err err);

#endif
