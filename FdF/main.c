/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:18:24 by username          #+#    #+#             */
/*   Updated: 2024/10/23 15:28:42 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	fdf->img.ptr = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.ptr, &fdf->img.bbp, &fdf->img.line_len, &fdf->img.endian);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (ft_printf("MONKE\n"), 1);
	fdf.map_h = 0;
	fdf.map_w = 0;
	if (!parse(argv[1], &fdf))
		return (1);
	if (init(&fdf))
		draw_map(fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.ptr, 0, 0);
	mlx_key_hook(fdf.win, on_press, &fdf);
	mlx_hook(fdf.win, 17, 1L << 0, graceful_exit, &fdf);
	mlx_loop(fdf.mlx);
}
