/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:07:25 by username          #+#    #+#             */
/*   Updated: 2024/10/23 14:07:47 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_press(int k_code, t_fdf *fdf)
{
	ft_printf("Key %i was pressed\n", k_code);
	if (k_code == XK_Escape)
		graceful_exit(fdf);
	if (k_code == XK_w)
		mlx_string_put(fdf->mlx, fdf->win, 1, 10, 9580735, "SUP");
	if (k_code == XK_space)
	{	
		fdf->iso = !fdf->iso;
		draw_map(*fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
	}
	if (k_code == XK_Down)
	{
		fdf->offset.y += 50;
		draw_map(*fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
	}
	if (k_code == XK_Up)
	{
		fdf->offset.y -= 50;
		draw_map(*fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
	}
	if (k_code == XK_Right)
	{
		fdf->offset.x += 50;
		draw_map(*fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
	}
	if (k_code == XK_Left)
	{
		fdf->offset.x -= 50;
		draw_map(*fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
	}
	if (k_code == XK_minus)
	{
		fdf->scale -= 5;
		draw_map(*fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
	}
	if (k_code == XK_equal)
	{
		fdf->scale += 5;
		draw_map(*fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
	}
	//ft_printf("ORIGIN: (%i, %i)\n", fdf->origin.x, fdf->origin.y);

	return (1);
}
