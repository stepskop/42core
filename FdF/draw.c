/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:42:41 by username          #+#    #+#             */
/*   Updated: 2024/10/23 16:03:54 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point iso(t_point point, int z)
{
	double a = 120;
	int	tmp;

	tmp = point.x;
	point.x = point.x * cos(a) + point.y * cos(a + 2) + z * cos(a - 2);
	point.y = tmp * sin(a) + point.y * sin(a + 2) + z * sin(a - 2);
	return (point);
}

void	draw_map(t_fdf fdf)
{
	int	i;
	int	j;
	t_point origin = {500, 500};
	int	step;

	if ((HEIGHT / fdf.map_h / 2) < (WIDTH / fdf.map_w / 2))
		step = (HEIGHT / fdf.map_h / 2);
	else
		step = (WIDTH / fdf.map_w / 2);
	step = 50;
	i = -1;
	while (fdf.map[++i])
	{
		j = -1;
		origin.x = 100;
		while(fdf.map[i][++j])
		{
			if (fdf.map[i][j + 1])
				draw_line(iso(origin, ft_atoi(fdf.map[i][j])), iso((t_point){origin.x + step, origin.y}, ft_atoi(fdf.map[i][j + 1])), fdf);
			if (fdf.map[i + 1] && is_inrow(fdf.map[i + 1], j))
				draw_line(iso(origin, ft_atoi(fdf.map[i][j])), iso((t_point){origin.x, origin.y + step}, ft_atoi(fdf.map[i + 1][j])), fdf);
			origin.x = origin.x + step;
		}
		origin.y += step;
	}
}
