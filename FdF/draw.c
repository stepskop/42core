/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:42:41 by username          #+#    #+#             */
/*   Updated: 2024/10/25 19:17:49 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	iso(int x, int y, t_fdf fdf)
{
	int		z;
	t_point	point;

	z = ft_atoi(fdf.map[y][x]);
	point.x = x * fdf.camera.scale;
	point.y = y * fdf.camera.scale;
	point = get_rotation(point, z, fdf);

	//TODO: Colors
	if (z == 0)
		point.color = 0x1F055C;
	else
		point.color = 0xB3102E;
	return (point);
}

static void	draw_map(t_fdf fdf)
{
	int	i;
	int	j;

	ft_bzero(fdf.img.addr, WIDTH * HEIGHT * (fdf.img.bbp / 8));
	i = -1;
	while (fdf.map[++i])
	{
		j = -1;
		while(fdf.map[i][++j])
		{
			if (fdf.map[i][j + 1])
				draw_line(fdf.cam_fn(j, i, fdf), fdf.cam_fn(j + 1, i, fdf), fdf);
			if (fdf.map[i + 1] && is_inrow(fdf.map[i + 1], j))
				draw_line(fdf.cam_fn(j, i, fdf), fdf.cam_fn(j, i + 1, fdf), fdf);
		}
	}
}

void	render(t_fdf fdf)
{
	draw_map(fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.ptr, 0, 0);
}

