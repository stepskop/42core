/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:46:47 by username          #+#    #+#             */
/*   Updated: 2024/10/30 21:18:15 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			set_z(ft_atoi(fdf->map.raw[i][j]), fdf);
			if (!add_pt(fdf, i, j))
				return (0);
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
		if (line && !add_str(fdf, line, &i))
			return (finish_read(fd), free(line), 0);
	}
	fdf->map.h = i + 1;
	if (!to_points(fdf))
		return (free_map(fdf->map.raw), 0);
	return (1);
}
