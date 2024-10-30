/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:46:19 by username          #+#    #+#             */
/*   Updated: 2024/10/30 16:58:59 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_point pix, t_data data)
{
	char	*dst;
	int		x;
	int		y;

	x = round(pix.x);
	y = round(pix.y);
	if (x < 1 || x > WIDTH - 1 || y < 1 || y > HEIGHT - 1)
		return ;
	dst = data.addr + (y * data.line_len + x * (data.bbp / 8));
	*(int *)dst = pix.color;
}
