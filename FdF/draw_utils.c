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

void	put_pixel(t_point pix, t_data data, int color)
{
	char	*dst;

	if (pix.x < 1 || pix.x > WIDTH - 1 || pix.y < 1 || pix.y > HEIGHT - 1)
		return ;
	dst = data.addr + (pix.y * data.line_len + pix.x * (data.bbp / 8));
	*(unsigned int *)dst = color;
}
