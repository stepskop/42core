/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:06:06 by username          #+#    #+#             */
/*   Updated: 2024/10/23 14:22:54 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	graceful_exit(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.ptr);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free_map(fdf->map);
	free(fdf->mlx);
	exit (0);
}
