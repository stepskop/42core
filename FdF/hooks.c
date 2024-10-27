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

static void	control_angle(int k_code, t_fdf *fdf)
{
	if (k_code == XK_w)
		fdf->camera.x_angle -= 0.1;
	else if (k_code == XK_s)
		fdf->camera.x_angle += 0.1;
	else if (k_code == XK_a)
		fdf->camera.y_angle -= 0.1;
	else if (k_code == XK_d)
		fdf->camera.y_angle += 0.1;
	else if (k_code == XK_5)
		fdf->camera.z_angle += 0.1;
	else if (k_code == XK_6)
		fdf->camera.z_angle -= 0.1;
	else if (k_code == XK_r)
	{
		fdf->camera.x_angle = -0.523599;
		fdf->camera.y_angle = -0.523599;
		fdf->camera.z_angle = 0.523599;
		fdf->camera.elev = -0.4;
	}
}

static void	control_scale(int k_code, t_fdf *fdf)
{
	if (k_code == XK_minus)
		fdf->camera.scale -= 1;
	else if (k_code == XK_equal)
		fdf->camera.scale += 1;
	else if (k_code == XK_i)
		fdf->camera.elev += 0.1;
	else if (k_code == XK_k)
		fdf->camera.elev -= 0.1;
}

static void	control_position(int k_code, t_fdf *fdf)
{
	if (k_code == XK_Down)
		fdf->camera.offset.y += 10;
	else if (k_code == XK_Up)
		fdf->camera.offset.y -= 10;
	else if (k_code == XK_Right)
		fdf->camera.offset.x += 10;
	else if (k_code == XK_Left)
		fdf->camera.offset.x -= 10;
}

int	on_press(int k_code, t_fdf *fdf)
{
	//ft_printf("Key %i was pressed\n", k_code);
	if (k_code == XK_Escape)
		graceful_exit(fdf);
	else if (k_code >= 65361 && k_code <= 65364)
		control_position(k_code, fdf);
	else if (k_code == 45 || k_code == 61 || k_code == XK_i || k_code == XK_k)
		control_scale(k_code, fdf);
	else
		control_angle(k_code, fdf);
	render(*fdf);
	return (1);
}
