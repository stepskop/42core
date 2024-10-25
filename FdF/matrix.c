/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:49:40 by username          #+#    #+#             */
/*   Updated: 2024/10/25 19:34:06 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, t_fdf fdf)
{
	int	tmp;
	double	angle;

	angle = fdf.camera.x_angle;
	tmp = *y;
	*y = *y * cos(angle) - *z * sin(angle);
	*z = tmp * sin(angle) + *z * cos(angle);
}

void	rotate_y(int *x, int *z, t_fdf fdf)
{
	int	tmp;
	double	angle;

	angle = fdf.camera.y_angle;
	tmp = *x;
	*x = *x * cos(angle) + *z * sin(angle);
	*z = *z * cos(angle) - tmp * sin(angle);
}

void	rotate_z(int *x, int *y, t_fdf fdf)
{
	int	tmp;
	double	angle;

	angle = fdf.camera.z_angle;
	tmp = *x;
	*x = *x * cos(angle) - *y * sin(angle);
	*y = tmp * sin(angle) + *y * cos(angle);
}

t_point	project(t_point point, int z, t_fdf fdf)
{
	int	mut_z;

	z *= fdf.camera.scale * 0.2;
	point.x -= (fdf.map_w * fdf.camera.scale) / 2;
	point.y -= (fdf.map_h * fdf.camera.scale) / 2;

	mut_z = z;
	rotate_x(&point.y, &mut_z, fdf);
	rotate_y(&point.x, &mut_z, fdf);
	rotate_z(&point.x, &point.y, fdf);

	point.y += HEIGHT / 2 + fdf.offset.y;
	point.x += WIDTH / 2 + fdf.offset.x;
	return (point);
}
