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

static int	display_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	fdf->img.ptr = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.ptr, &fdf->img.bbp,
			&fdf->img.line_len, &fdf->img.endian);
	return (1);
}

static void	camera_init(t_fdf *fdf)
{
	if ((HEIGHT / fdf->map_h / 2) < (WIDTH / fdf->map_w / 2))
		fdf->camera.scale = (HEIGHT / fdf->map_h / 2);
	else
		fdf->camera.scale = (WIDTH / fdf->map_w / 2);
	fdf->camera.x_angle = -0.523599;
	fdf->camera.y_angle = -0.523599;
	fdf->camera.z_angle = 0.523599;
	fdf->camera.elev = -0.4;
	fdf->camera.offset = (t_point){0,0, -1};
	fdf->cam_fn = &iso;
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (ft_printf("MONKE\n"), 1);
	fdf.map_h = 0;
	fdf.map_w = 0;
	if (!parse(argv[1], &fdf) || !fdf.map_h || !fdf.map_w)
		return (1);
	camera_init(&fdf);
	if (display_init(&fdf))
		render(fdf);
	mlx_key_hook(fdf.win, on_press, &fdf);
	mlx_hook(fdf.win, 17, 1L << 0, graceful_exit, &fdf);
	mlx_loop(fdf.mlx);
}
