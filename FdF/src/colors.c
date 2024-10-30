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

int	set_color(int z, t_map map)
{
	return (gradient(BOT_COLOR, TOP_COLOR, map.max.z - map.min.z, z));
}
