/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:07:25 by username          #+#    #+#             */
/*   Updated: 2024/10/30 01:28:23 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	control_angle(int k_code, t_fdf *fdf)
{
	if (k_code == XK_w)
		rot_x(fdf, 0.1);
	else if (k_code == XK_s)
		rot_x(fdf, -0.1);
	else if (k_code == XK_a)
		rot_y(fdf, -0.1);
	else if (k_code == XK_d)
		rot_y(fdf, 0.1);
}

static void	control_scale(int k_code, t_fdf *fdf)
{
	if (k_code == XK_minus)
		zoom(fdf, 0.9);
	else if (k_code == XK_equal)
		zoom(fdf, 1.1);
	else if (k_code == XK_i)
		elev(fdf, 1.1);
	else if (k_code == XK_k)
		elev(fdf, 0.9);
}

static void	control_position(int k_code, t_fdf *fdf)
{
	if (k_code == XK_Down)
		move(fdf, (t_point){0, 10, 0, 0});
	else if (k_code == XK_Up)
		move(fdf, (t_point){0, -10, 0, 0});
	else if (k_code == XK_Right)
		move(fdf, (t_point){10, 0, 0, 0});
	else if (k_code == XK_Left)
		move(fdf, (t_point){-10, 0, 0, 0});
}

//ft_printf("Key %i was pressed\n", k_code);
int	on_press(int k_code, t_fdf *fdf)
{
	if (k_code == XK_Escape)
		graceful_exit(fdf);
	else if (k_code >= 65361 && k_code <= 65364)
		control_position(k_code, fdf);
	else if (k_code == 45 || k_code == 61 || k_code == XK_i || k_code == XK_k)
		control_scale(k_code, fdf);
	else
		control_angle(k_code, fdf);
	render(fdf);
	return (1);
}
