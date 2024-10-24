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

t_point	apply_angle(t_point point, int z, t_fdf fdf)
{
	double a = fdf.angle;
	int	tmp;

	tmp = point.x;
	point.x = point.x * cos(a) + point.y * cos(a + 2) + z * (fdf.scale * 1) * cos(a - 2);
	point.y = tmp * sin(a) + point.y * sin(a + 2) + z * (fdf.scale * 1) * sin(a - 2);
	return (point);
}

int	get_w_mid(t_fdf fdf)
{
	int res;
	int max_x = 0;
	int min_x = 0;

	//WORKS ONLY ON RECTANGULAR MAPS
	min_x = apply_angle((t_point){fdf.origin.x, fdf.origin.y + ((fdf.map_h - 1) * fdf.scale)}, ft_atoi(fdf.map[fdf.map_h - 1][0]), fdf).x;
	max_x = apply_angle((t_point){fdf.origin.x + ((fdf.map_w - 1) * fdf.scale), fdf.origin.y}, ft_atoi(fdf.map[0][fdf.map_w - 1]), fdf).x;
	res = min_x + max_x;
	return (res / 2);
}

t_point iso(t_point point, int z, t_fdf fdf)
{
	point = apply_angle(point, z, fdf);
	point.x = point.x + (WIDTH / 2 - get_w_mid(fdf));

	point.x += fdf.offset.x;
	point.y += fdf.offset.y;
	return (point);
}

void	draw_map(t_fdf fdf)
{
	int	i;
	int	j;
	int	step;
	ft_bzero(fdf.img.addr, WIDTH * HEIGHT * (fdf.img.bbp / 8));
	step = fdf.scale;
	t_point origin = {fdf.origin.x, fdf.origin.y};
	i = -1;
	if (1)
	{
		origin = (t_point){fdf.origin.x, fdf.origin.y};
		while (fdf.map[++i])
		{
			j = -1;
			origin.x = fdf.origin.x;
			while(fdf.map[i][++j])
			{
				if (fdf.map[i][j + 1])
					draw_line(iso(origin, ft_atoi(fdf.map[i][j]), fdf), iso((t_point){origin.x + step, origin.y}, ft_atoi(fdf.map[i][j + 1]), fdf), fdf);
				if (fdf.map[i + 1] && is_inrow(fdf.map[i + 1], j))
					draw_line(iso(origin, ft_atoi(fdf.map[i][j]), fdf), iso((t_point){origin.x, origin.y + step}, ft_atoi(fdf.map[i + 1][j]), fdf), fdf);
				origin.x = origin.x + step;
			}
			origin.y += step;
		}
	}
	if (fdf.iso)
	{
		i = -1;
		origin = (t_point){fdf.origin.x + fdf.offset.x, fdf.origin.y + fdf.offset.y};
		while (fdf.map[++i])
		{
			j = -1;
			origin.x = fdf.origin.x + fdf.offset.x;
			while(fdf.map[i][++j])
			{
				if (fdf.map[i][j + 1])
					draw_line(origin, (t_point){origin.x + step, origin.y}, fdf);
				if (fdf.map[i + 1] && is_inrow(fdf.map[i + 1], j))
					draw_line(origin, (t_point){origin.x, origin.y + step}, fdf);
				origin.x = origin.x + step;
			}
			origin.y += step;
		}
	}
}
