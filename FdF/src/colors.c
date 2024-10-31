/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:45:15 by username          #+#    #+#             */
/*   Updated: 2024/10/30 22:50:10 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	interpol_color(int start, int end, double f)
{
	int	sta_rgb[3];
	int	end_rgb[3];
	int	res_rgb[3];

	sta_rgb[0] = (start >> 16) & 0xFF;
	sta_rgb[1] = (start >> 8) & 0xFF;
	sta_rgb[2] = start & 0xFF;
	end_rgb[0] = (end >> 16) & 0xFF;
	end_rgb[1] = (end >> 8) & 0xFF;
	end_rgb[2] = end & 0xFF;
	res_rgb[0] = sta_rgb[0] + (int)((end_rgb[0] - sta_rgb[0]) * f);
	res_rgb[1] = sta_rgb[1] + (int)((end_rgb[1] - sta_rgb[1]) * f);
	res_rgb[2] = sta_rgb[2] + (int)((end_rgb[2] - sta_rgb[2]) * f);
	return ((res_rgb[0] << 16) | (res_rgb[1] << 8) | res_rgb[2]);
}

int	set_color(int z, t_map map)
{
	double	f;

	if (map.max.z == map.min.z)
		return (BOT_COLOR);
	f = (z - map.min.z) / (map.max.z - map.min.z);
	return (interpol_color(BOT_COLOR, TOP_COLOR, f));
}

int	get_color(t_point start, t_point end, t_point curr)
{
	double	f;
	double	totl_dis;
	double	curr_dis;

	totl_dis = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	curr_dis = sqrt(pow(curr.x - start.x, 2) + pow(curr.y - start.y, 2));
	if (totl_dis == 0)
		return (start.color);
	f = curr_dis / totl_dis;
	return (interpol_color(start.color, end.color, f));
}
