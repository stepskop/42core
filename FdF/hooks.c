/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:07:25 by username          #+#    #+#             */
/*   Updated: 2024/10/25 19:25:58 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	re_render(t_fdf *fdf)
{
	draw_map(*fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
}

static void	control_angle(int k_code, t_fdf *fdf)
{
	if (k_code == XK_1)
		fdf->camera.x_angle += 0.1;
	else if (k_code == XK_2)
		fdf->camera.x_angle -= 0.1;
	else if (k_code == XK_3)
		fdf->camera.y_angle += 0.1;
	else if (k_code == XK_4)
		fdf->camera.y_angle -= 0.1;
	else if (k_code == XK_5)
		fdf->camera.z_angle += 0.1;
	else if (k_code == XK_6)
		fdf->camera.z_angle -= 0.1;
	else if (k_code == XK_r)
	{
		fdf->camera.x_angle = M_PI * 0.17;
		fdf->camera.y_angle = M_PI * -0.17;
		fdf->camera.z_angle = M_PI * 0;
	}
}

static void	control_scale(int k_code, t_fdf *fdf)
{
	if (k_code == XK_minus)
		fdf->camera.scale -= 1;
	else if (k_code == XK_equal)
		fdf->camera.scale += 1;
}

static void	control_position(int k_code, t_fdf *fdf)
{
	if (k_code == XK_Down)
		fdf->offset.y += 10;
	else if (k_code == XK_Up)
		fdf->offset.y -= 10;
	else if (k_code == XK_Right)
		fdf->offset.x += 10;
	else if (k_code == XK_Left)
		fdf->offset.x -= 10;
}

int	on_press(int k_code, t_fdf *fdf)
{
	ft_printf("Key %i was pressed\n", k_code);
	if (k_code == XK_Escape)
		graceful_exit(fdf);
	else if (k_code == XK_w)
		mlx_string_put(fdf->mlx, fdf->win, 1, 10, 9580735, "SUP");
	else if (k_code == XK_space)
		fdf->iso = !fdf->iso;
	else if (k_code >= 49 && k_code <= 54)
		control_angle(k_code, fdf);
	else if (k_code >= 65361 && k_code <= 65364)
		control_position(k_code, fdf);
	else if (k_code == 45 || k_code == 61)
		control_scale(k_code, fdf);
	re_render(fdf);
	return (1);
}
