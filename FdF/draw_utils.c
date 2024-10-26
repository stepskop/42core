/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:46:19 by username          #+#    #+#             */
/*   Updated: 2024/10/23 13:52:45 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_point pix, t_data data)
{
	char	*dst;

	if (pix.x < 1 || pix.x > WIDTH - 1 || pix.y < 1 || pix.y > HEIGHT - 1)
		return ;
	dst = data.addr + (pix.y * data.line_len + pix.x * (data.bbp / 8));
	*(unsigned int *)dst = pix.color;
}

//TODO: Colors
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

int get_color(t_point start, t_point end, t_point current)
{
	float total_distance = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	float current_distance = sqrt(pow(current.x - start.x, 2) + pow(current.y - start.y, 2));

	if (total_distance == 0) {
		return start.color;
	}

	float t = current_distance / total_distance;

	return interpolate_color(start.color, end.color, t);
}
