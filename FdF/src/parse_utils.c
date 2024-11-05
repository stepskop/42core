/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:08:18 by username          #+#    #+#             */
/*   Updated: 2024/10/30 22:47:19 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	line_len(char **line)
{
	size_t	len;

	len = 0;
	while (line && line[len])
		len++;
	return (len);
}

int	add_str(t_fdf *fdf, char *line, size_t *i)
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
	if (!fdf->map.raw[*i])
		return (0);
	fdf->map.raw[*i + 1] = NULL;
	len = line_len(fdf->map.raw[*i]);
	if (len != fdf->map.w)
		return (0);
	return (1);
}

static int	init_color(t_point *new_point, char *map_str, t_map map)
{
	char	**splitted;
	size_t	m_len;

	m_len = 0;
	splitted = ft_split(map_str, ',');
	if (!splitted)
		return (0);
	new_point->z = ft_atoi(splitted[0]);
	while (splitted[m_len])
		m_len++;
	if (m_len != 1)
		new_point->color = ft_atoi_base(ft_strchr(splitted[1], 'x') + 1, 16);
	else
		new_point->color = set_color(new_point->z, map);
	while (m_len > 0)
		free(splitted[m_len-- - 1]);
	free(splitted);
	return (1);
}

int	add_pt(t_fdf *fdf, int i, int j)
{
	t_point	*new_point;

	fdf->map.pts[i][j] = malloc(sizeof(t_point));
	new_point = fdf->map.pts[i][j];
	if (!new_point)
		return (0);
	new_point->x = (j - fdf->map.w / 2) * 10;
	new_point->y = (i - fdf->map.h / 2) * 10;
	if (!init_color(new_point, fdf->map.raw[i][j], fdf->map))
		return (free(new_point), fdf->map.pts[i][j] = NULL, 0);
	return (1);
}

int	set_z(t_fdf *fdf)
{
	int	i;
	int	j;
	int	curr;

	i = -1;
	while (fdf->map.raw[++i])
	{
		j = -1;
		while (fdf->map.raw[i][++j])
		{
			curr = ft_atoi(fdf->map.raw[i][j]);
			if (curr > fdf->map.max.z)
				fdf->map.max.z = curr;
			if (curr < fdf->map.min.z)
				fdf->map.min.z = curr;
		}
	}
	return (1);
}
