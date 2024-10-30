/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:20:16 by username          #+#    #+#             */
/*   Updated: 2024/10/30 22:45:56 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_h(t_point from, t_point to, t_data img)
{
	int		dec;
	int		dir;
	t_point	delt;
	t_point	curr;

	delt = v_sub(to, from);
	dir = 1;
	if (delt.y < 0)
		dir = -1;
	delt.y = fabs(delt.y);
	dec = 2 * delt.y - delt.x;
	curr = from;
	while (curr.x < to.x)
	{
		put_pixel(curr, img);
		if (dec > 0)
			curr.y += dir;
		if (dec > 0)
			dec = dec + (2 * (delt.y - delt.x));
		else
			dec = dec + 2 * delt.y;
		//curr.color = gradient(from.color, to.color, 10, curr.z);
		curr.x++;
	}
	return (0);
}

int	draw_v(t_point from, t_point to, t_data img)
{
	int		dec;
	int		dir;
	t_point	delt;
	t_point	curr;

	delt = v_sub(to, from);
	dir = 1;
	if (delt.x < 0)
		dir = -1;
	delt.x = fabs(delt.x);
	dec = 2 * delt.x - delt.y;
	curr = from;
	while (curr.y < to.y)
	{
		put_pixel(curr, img);
		if (dec > 0)
			curr.x += dir;
		if (dec > 0)
			dec = dec + (2 * (delt.x - delt.y));
		else
			dec = dec + 2 * delt.x;
		//curr.color = gradient(from.color, to.color, 10, curr.z);
		curr.y++;
	}
	return (0);
}

void	draw_line(t_point from, t_point to, t_fdf fdf)
{
	int	tmp;

	tmp = from.color;
	if (fabs(to.y - from.y) < fabs(to.x - from.x))
	{
		if (from.x > to.x)
		{
			from.color = to.color;
			to.color = tmp;
			draw_h(to, from, fdf.img);
			return ;
		}
		draw_h(from, to, fdf.img);
	}
	else
	{
		if (from.y > to.y)
		{
			from.color = to.color;
			to.color = tmp;
			draw_v(to, from, fdf.img);
			return ;
		}
		draw_v(from, to, fdf.img);
	}
}
