/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:18:24 by username          #+#    #+#             */
/*   Updated: 2024/10/25 19:33:36 by username         ###   ########.fr       */
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
	fdf.iso = 0;
	fdf.camera.x_angle = M_PI * 0.17;
	fdf.camera.y_angle = M_PI * -0.17;		
	fdf.camera.z_angle = M_PI * 0;
	fdf.offset = (t_point){0, 0};
	if (!parse(argv[1], &fdf))
		return (1);
	if ((HEIGHT / fdf.map_h / 2) < (WIDTH / fdf.map_w / 2))
		fdf.camera.scale = (HEIGHT / fdf.map_h / 2);
	else
		fdf.camera.scale = (WIDTH / fdf.map_w / 2);
	//fdf.camera.scale = 1;
	//fdf.origin = (t_point){(WIDTH / 2) - (fdf.map_w / 2) * fdf.camera.scale, (HEIGHT / 2) - (fdf.map_h / 2) * fdf.camera.scale};
	fdf.origin = (t_point){0, 0};
	if (init(&fdf))
		draw_map(fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.ptr, 0, 0);
	mlx_key_hook(fdf.win, on_press, &fdf);
	mlx_hook(fdf.win, 17, 1L << 0, graceful_exit, &fdf);
	mlx_loop(fdf.mlx);
}
