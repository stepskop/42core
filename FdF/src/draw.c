/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:42:41 by username          #+#    #+#             */
/*   Updated: 2024/10/30 01:27:41 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	proj_iso(t_fdf *fdf)
{
	rot_x(fdf, -M_PI_2);
	rot_y(fdf, M_PI_4);
	rot_x(fdf, 2);
}

static void	draw_map(t_fdf fdf)
{
	int		i;
	int		j;
	t_point	curr;

	i = -1;
	while (fdf.map.pts[++i])
	{
		j = -1;
		while (fdf.map.pts[i][++j])
		{
			curr = v_add(*(fdf.map.pts[i][j]), fdf.cam.offs);
			if (fdf.map.raw[i][j + 1])
				draw_line(curr,
					v_add(*(fdf.map.pts[i][j + 1]), fdf.cam.offs), fdf);
			if (fdf.map.raw[i + 1])
				draw_line(curr,
					v_add(*(fdf.map.pts[i + 1][j]), fdf.cam.offs), fdf);
		}
	}
}

void	render(t_fdf *fdf)
{
	if (fdf->img.ptr)
		mlx_destroy_image(fdf->mlx, fdf->img.ptr);
	fdf->img.ptr = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.ptr, &fdf->img.bbp,
			&fdf->img.line_len, &fdf->img.endian);
	draw_map(*fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
}
