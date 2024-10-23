/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:07:25 by username          #+#    #+#             */
/*   Updated: 2024/10/23 14:07:47 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_press(int k_code, t_fdf *fdf)
{
	ft_printf("Key %i was pressed\n", k_code);
	if (k_code == XK_Escape)
		graceful_exit(fdf);
	if (k_code == XK_w)
		mlx_string_put(fdf->mlx, fdf->win, 1, 10, 9580735, "SUP");
	return (1);
}
