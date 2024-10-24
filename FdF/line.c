/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:16:21 by username          #+#    #+#             */
/*   Updated: 2024/10/23 14:16:50 by username         ###   ########.fr       */
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
}

static void	draw_h(t_point from, t_point to, t_fdf fdf)
{
	int	dec;
	int	dir;
	int	dx;
	int	dy;
	int	color = 16777215;

	if (from.x > to.x)
		swap(&from, &to);
	dx = to.x - from.x;
	dy = to.y - from.y;
	dec = 2 * dy - dx;
	dir = 1;
	if (dy < 0)
		dir = -1;
	dy *= dir;
	while (from.x <= to.x)
	{
		put_pixel((t_point){(from.x)++, from.y}, fdf.img, color -= 255);
		if (dec > 0)
		{
			dec = dec - 2 * dx;
			from.y += dir;
		}
		dec = dec + 2 * dy;
	}
}

static void	draw_v(t_point from, t_point to, t_fdf fdf)
{
	int	dec;
	int	dir;
	int	dx;
	int	dy;
	int	color = 16777215;

	if (from.y > to.y)
		swap(&from, &to);
	dx = to.x - from.x;
	dy = to.y - from.y;
	dec = 2 * dx - dy;
	dir = 1;
	if (dx < 0)
		dir = -1;
	dx *= dir;
	while (from.y <= to.y)
	{
		put_pixel((t_point){from.x, (from.y)++}, fdf.img, color -= 255);
		if (dec > 0)
		{
			dec = dec - 2 * dy;
			from.x += dir;
		}
		dec = dec + 2 * dx;
	}
}

void	draw_line(t_point from, t_point to, t_fdf fdf)
{
	if (abs(to.x - from.x) > abs(to.y - from.y))
		draw_h(from, to, fdf);
	else
		draw_v(from, to, fdf);
}
