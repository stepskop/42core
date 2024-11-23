/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:35:06 by username          #+#    #+#             */
/*   Updated: 2024/11/22 15:36:36 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

typedef struct s_cmd
{
	char	*path;
	char	**args;
	int		pid;
	char	**full_cmd;
}	t_cmd;

// Utils
char	*get_cmd(char *cmd, char **env);
void	free_starr(char **starr);

#endif
