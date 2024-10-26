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
	tmp = a->color;
	a->color = b->color;
	b->color = tmp;
}

static void	draw_h(t_point from, t_point to, t_fdf fdf)
{
	int		dec;
	int		dir;
	int		dx;
	int		dy;
	t_point start;

	start = (t_point){from.x, from.y, from.color};
	dx = to.x - from.x;
	dy = to.y - from.y;
	dec = 2 * dy - dx;
	dir = 1;
	if (dy < 0)
		dir = -1;
	dy *= dir;
	while (from.x <= to.x)
	{
		put_pixel((t_point){(from.x)++, from.y, get_color(start, to, from)}, fdf.img);
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
	int		dec;
	int		dir;
	int		dx;
	int		dy;
	t_point	start;

	start = (t_point){from.x, from.y, from.color};
	dx = to.x - from.x;
	dy = to.y - from.y;
	dec = 2 * dx - dy;
	dir = 1;
	if (dx < 0)
		dir = -1;
	dx *= dir;
	while (from.y <= to.y)
	{
		put_pixel((t_point){from.x, (from.y)++, get_color(start, to, from)}, fdf.img);
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
	//ft_printf("FROM: [%i, %i, %#x], TO: [%i, %i, %#x]\n", from.x, from.y, from.color, to.x, to.y, to.color);
	if (abs(to.x - from.x) > abs(to.y - from.y))
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
