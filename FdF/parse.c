/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:46:47 by username          #+#    #+#             */
/*   Updated: 2024/10/23 15:27:11 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	add_new(t_fdf *fdf, char *line, size_t *i)
{
	char	***tmp;
	int		len;

	tmp = fdf->map;
	fdf->map = ft_realloc(fdf->map, (*i + 1) * sizeof(char **),
			(*i + 3) * sizeof(char **));
	if (!fdf->map)
		return (free_map(tmp), 0);
	(*i)++;
	fdf->map[*i] = ft_split(line, ' ');
	fdf->map[*i + 1] = NULL;
	len = 0;
	while (fdf->map[*i] && fdf->map[*i][len])
		len++;
	if (len > fdf->map_w)
		fdf->map_w = len;
	return (1);
}

int	parse(char *file, t_fdf *fdf)
{
	int		fd;
	size_t	i;
	char	*line;

	fdf->map = NULL;
	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	fdf->map = malloc(sizeof(char **) * 2);
	if (!line || !fdf->map)
		return (free(fdf->map), 0);
	fdf->map[i] = ft_split(line, ' ');
	fdf->map[i + 1] = NULL;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && !add_new(fdf, line, &i))
			return (0);
	}
	fdf->map_h = i;
	return (1);
}
