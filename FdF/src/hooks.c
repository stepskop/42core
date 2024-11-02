/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:07:25 by username          #+#    #+#             */
/*   Updated: 2024/10/30 16:55:51 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_map(t_fdf *fdf)
{
	int	i;
	int	j;


	i = -1;
	while (fdf->map.pts[++i])
	{
		j = -1;
		while (fdf->map.pts[i][++j])
		{
			fdf->map.pts[i][j]->x = (j - fdf->map.w / 2) * 10;
			fdf->map.pts[i][j]->y = (i - fdf->map.h / 2) * 10;
			fdf->map.pts[i][j]->z = -ft_atoi(fdf->map.raw[i][j]);
		}
	}
	// rot_x(fdf, -M_PI_2);
	// rot_y(fdf, M_PI_4);
	// rot_x(fdf, 1);
	fdf->cam.back = (t_matrix)
		{1, 0, 0,
		0, 1, 0,
		0, 0, 1};
}

static void	control_angle(int k_code, t_fdf *fdf)
{
	if (k_code == XK_w)
		rot_x(fdf, -0.1);
	else if (k_code == XK_s)
		rot_x(fdf, 0.1);
	else if (k_code == XK_a)
		rot_y(fdf, 0.1);
	else if (k_code == XK_d)
		rot_y(fdf, -0.1);
	else if (k_code == XK_e)
		rot_z(fdf, 0.1);
	else if (k_code == XK_q)
		rot_z(fdf, -0.1);
}

static void	control_scale(int k_code, t_fdf *fdf)
{
	if (k_code == XK_minus)
		zoom(fdf, 1 / 1.2);
	else if (k_code == XK_equal)
		zoom(fdf, 1.2);
	else if (k_code == XK_i)
		elev(fdf, 1 / 1.2);
	else if (k_code == XK_k)
		elev(fdf, 1.2);
}

static void	control_position(int k_code, t_fdf *fdf)
{
	if (k_code == XK_Down)
		fdf->cam.offs = v_add(fdf->cam.offs, (t_point){0, 10, 0, 0});
	else if (k_code == XK_Up)
		fdf->cam.offs = v_add(fdf->cam.offs, (t_point){0, -10, 0, 0});
	else if (k_code == XK_Right)
		fdf->cam.offs = v_add(fdf->cam.offs, (t_point){10, 0, 0, 0});
	else if (k_code == XK_Left)
		fdf->cam.offs = v_add(fdf->cam.offs, (t_point){-10, 0, 0, 0});
}

int	on_press(int k_code, t_fdf *fdf)
{
	if (k_code == XK_Escape)
		graceful_exit(fdf);
	else if (k_code >= 65361 && k_code <= 65364)
		control_position(k_code, fdf);
	else if (k_code == 45 || k_code == 61 || k_code == XK_i || k_code == XK_k)
		control_scale(k_code, fdf);
	else if (k_code == XK_p)
		fdf->cam.pers = !fdf->cam.pers;
	else if (k_code == XK_r)
		reset_map(fdf);
	else
		control_angle(k_code, fdf);
	render(fdf);
	return (1);
}
