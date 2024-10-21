/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:18:24 by username          #+#    #+#             */
/*   Updated: 2024/10/21 14:10:37 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	graceful_exit(t_fdf fdf)
{
	mlx_destroy_window(fdf.mlx, fdf.win);
	mlx_destroy_display(fdf.mlx);
	free(fdf.mlx);
	exit (0);
}

int	on_press(int k_code, t_fdf *fdf)
{
	ft_printf("Key %i was pressed\n", k_code);
	if (k_code == XK_Escape)
		graceful_exit(*fdf);
	if (k_code == XK_w)
		mlx_string_put(fdf->mlx, fdf->win, 1, 10, 9580735, "SUP");
	return (1);
}

int	main(void)
{
	t_fdf	fdf;
	
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 800, 600, "FdF");
	mlx_key_hook(fdf.win, &on_press, &fdf);
	mlx_loop(fdf.mlx);
}
