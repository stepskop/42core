/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:16:21 by username          #+#    #+#             */
/*   Updated: 2024/10/30 01:36:27 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	swap(t_point *a, t_point *b)
{
	int	tmp;

	tmp = a->x;
	a->x = b->x;
	b->x = tmp;
	tmp = a->y;
	a->y = b->y;
	b->y = tmp;
	tmp = a->z;
	a->z = b->z;
	b->z = tmp;
	tmp = a->color;
	a->color = b->color;
	b->color = tmp;
}

static void	draw_h(t_point from, t_point to, t_fdf fdf)
{
	double		dec;
	double		dir;
	t_point		d;
	t_point		start;

	start = (t_point){from.x, from.y, from.z, from.color};
	d.x = to.x - from.x;
	d.y = to.y - from.y;
	dec = 2 * d.y - d.x;
	dir = 1;
	if (d.y < 0)
		dir = -1;
	d.y *= dir;
	while (from.x <= to.x)
	{
		put_pixel((t_point){(from.x)++, from.y, from.z, 0xFFFFFF}, fdf.img);
		if (dec > 0)
		{
			dec = dec - 2 * d.x;
			from.y += dir;
		}
		dec = dec + 2 * d.y;
	}
}

static void	draw_v(t_point from, t_point to, t_fdf fdf)
{
	double		dec;
	double		dir;
	t_point		d;
	t_point		start;

	start = (t_point){from.x, from.y, from.z, from.color};
	d.x = to.x - from.x;
	d.y = to.y - from.y;
	dec = 2 * d.x - d.y;
	dir = 1;
	if (d.x < 0)
		dir = -1;
	d.x *= dir;
	while (from.y <= to.y)
	{
		put_pixel((t_point){from.x, (from.y)++, from.z, 0xFFFFFF}, fdf.img);
		if (dec > 0)
		{
			dec = dec - 2 * d.y;
			from.x += dir;
		}
		dec = dec + 2 * d.x;
	}
}

void	draw_line(t_point from, t_point to, t_fdf fdf)
{
	if (fabs(to.x - from.x) > fabs(to.y - from.y))
	{
		if (from.x > to.x)
			swap(&from, &to);
		draw_h(from, to, fdf);
	}
	else
	{
		if (from.y > to.y)
			swap(&from, &to);
		draw_v(from, to, fdf);
	}
}
