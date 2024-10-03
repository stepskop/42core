/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:33:35 by username          #+#    #+#             */
/*   Updated: 2024/10/01 19:22:36 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strdup(const char *s)
{
	size_t	str_len;
	char	*ptr;

	str_len = ft_strlen(s);
	ptr = malloc((str_len * sizeof(char)) + 1);
	if (!ptr)
		return (NULL);
	ptr[str_len] = '\0';
	while (str_len-- > 0)
		ptr[str_len] = s[str_len];
	return (ptr);
}

static char	*get_line(char *str)
{
	size_t	i;
	char	*line;
	char	*l_txt;

	i = 0;
	if (!str || !str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	l_txt = ft_substr(str, 0, i + (str[i] == '\n'));
	line = NULL;
	if (l_txt)
		line = malloc((ft_strlen(l_txt) + 1) * sizeof(char));
	if (!line)
		return (free(l_txt), NULL);
	i = -1;
	while (l_txt[++i])
		line[i] = l_txt[i];
	line[i] = '\0';
	free(l_txt);
	return (line);
}

static char	*shift_vault(char *str, size_t line_len)
{
	if (!str || !*str)
		return (NULL);
	str += line_len;
	if (!*str)
		return (NULL);
	return (ft_strdup(str));
}

static char	*read_next(char *vault, char *buf, int fd)
{
	int		rd;
	char	*tmp;

	rd = 1;
	while (rd > 0 && vault)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(vault);
			vault = NULL;
			break ;
		}
		buf[rd] = '\0';
		tmp = vault;
		vault = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (vault);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*vault[MAX_FD];
	char		*new_vault;
	char		*buf;

	line = NULL;
	new_vault = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free(vault[fd]), vault[fd] = NULL, NULL);
	if (!vault[fd])
		vault[fd] = ft_strdup("");
	vault[fd] = read_next(vault[fd], buf, fd);
	line = get_line(vault[fd]);
	if (line && vault[fd])
		new_vault = shift_vault(vault[fd], ft_strlen(line));
	free(vault[fd]);
	vault[fd] = new_vault;
	return (line);
}
