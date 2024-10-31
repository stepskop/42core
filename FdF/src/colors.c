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

int	gradient(int start, int end, int len, int curr)
{
	int		r;
	int		g;
	int		b;
	float	t;

	t = (float)curr / len;
	r = ((start >> 16) & 0xFF) + (int)(((end >> 16 & 0xFF) - (start >> 16 & 0xFF)) * t);
	g = ((start >> 8) & 0xFF) + (int)(((end >> 8 & 0xFF) - (start >> 8 & 0xFF)) * t);
	b = (start & 0xFF) + (int)(((end & 0xFF) - (start & 0xFF)) * t);
	return ((r << 16) | (g << 8) | b);
}

// int	get_clor()
// {
//
// }

int	set_color(int z, t_map map)
{
	return (gradient(BOT_COLOR, TOP_COLOR, map.max.z - map.min.z, z));
}

int interpolate_color(int start_color, int end_color, float t)
{
	int start_r = (start_color >> 16) & 0xFF;
	int start_g = (start_color >> 8) & 0xFF;
	int start_b = start_color & 0xFF;
	int end_r = (end_color >> 16) & 0xFF;
	int end_g = (end_color >> 8) & 0xFF;
	int end_b = end_color & 0xFF;
	int r = start_r + (int)((end_r - start_r) * t);
	int g = start_g + (int)((end_g - start_g) * t);
	int b = start_b + (int)((end_b - start_b) * t);
	return (r << 16) | (g << 8) | b;
}

int get_current_color(t_point start, t_point end, t_point current)
{
	float total_distance = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	float current_distance = sqrt(pow(current.x - start.x, 2) + pow(current.y - start.y, 2));
	if (total_distance == 0) {
		return start.color;
	}
	float t = current_distance / total_distance;
	return interpolate_color(start.color, end.color, t);
}
