/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:46:47 by username          #+#    #+#             */
/*   Updated: 2024/10/30 01:34:01 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	add_new(t_fdf *fdf, char *line, size_t *i)
{
	char	***tmp;
	int		len;

	tmp = fdf->map.raw;
	fdf->map.raw = ft_realloc(fdf->map.raw, (*i + 1) * sizeof(char **),
			(*i + 3) * sizeof(char **));
	if (!fdf->map.raw)
		return (free_map(tmp), 0);
	if (*i == 0)
		fdf->map.w = line_len(fdf->map.raw[0]);
	(*i)++;
	fdf->map.raw[*i] = ft_split(line, ' ');
	fdf->map.raw[*i + 1] = NULL;
	len = line_len(fdf->map.raw[*i]);
	if (len != fdf->map.w)
		return (free_map(fdf->map.raw), 0);
	return (1);
}

static int	to_points(t_fdf *fdf)
{
	int	i;
	int	j;

	fdf->map.pts = malloc(sizeof(t_point **) * (fdf->map.h + 1));
	if (!fdf->map.pts)
		return (0);
	i = -1;
	while (fdf->map.raw[++i])
	{
		j = -1;
		fdf->map.pts[i] = malloc(sizeof(t_point *) * (line_len(
						fdf->map.raw[i]) + 1));
		if (!fdf->map.pts[i])
			return (free_pts(fdf->map.pts), 0);
		while (fdf->map.raw[i][++j])
		{
			fdf->map.pts[i][j] = malloc(sizeof(t_point));
			if (!fdf->map.pts[i][j])
				return (free_pts(fdf->map.pts), 0);
			*(fdf->map.pts[i][j]) = (t_point){j - (double)fdf->map.w / 2,
				i - (double)fdf->map.h / 2, ft_atoi(fdf->map.raw[i][j]), 0};
		}
		fdf->map.pts[i][j] = NULL;
	}
	return (fdf->map.pts[i] = NULL, 1);
}

int	parse(char *file, t_fdf *fdf)
{
	int		fd;
	size_t	i;
	char	*line;

	fdf->map.raw = NULL;
	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	fdf->map.raw = malloc(sizeof(char **) * 2);
	if (!line || !fdf->map.raw)
		return (free(fdf->map.raw), 0);
	fdf->map.raw[i] = ft_split(line, ' ');
	fdf->map.raw[i + 1] = NULL;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && !add_new(fdf, line, &i))
			return (finish_read(fd), free(line), 0);
	}
	fdf->map.h = i + 1;
	if (!to_points(fdf))
		return (free_map(fdf->map.raw), 0);
	return (1);
}
