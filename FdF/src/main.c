/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:18:24 by username          #+#    #+#             */
/*   Updated: 2024/10/30 21:40:46 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	dis_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (0);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	if (!fdf->win)
		return (0);
	fdf->img.ptr = NULL;
	return (1);
}

static void	cam_init(t_fdf *fdf)
{
	fdf->cam.elev = 0;
	fdf->cam.pers = 0;
	fdf->cam.offs = (t_point){WIDTH / 2, HEIGHT / 2, 0, -1};
	fdf->cam.back = (t_matrix)
	{1, 0, 0, 0, 1, 0, 0, 0, 1};
}

static void	map_init(t_fdf *fdf)
{
	fdf->map.raw = NULL;
	fdf->map.pts = NULL;
	fdf->map.h = 0;
	fdf->map.w = 0;
	fdf->map.max = (t_point){0, 0, 0, TOP_COLOR};
	fdf->map.min = (t_point){0, 0, 0, BOT_COLOR};
}

static void	rot_init(t_fdf *fdf)
{
	rot_x(fdf, -M_PI_2);
	rot_y(fdf, M_PI_4);
	rot_x(fdf, 0.6);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (ft_printf("No file provided\n"), 1);
	fdf.map.h = 0;
	fdf.map.w = 0;
	fdf.mlx = NULL;
	fdf.win = NULL;
	fdf.img.ptr = NULL;
	cam_init(&fdf);
	map_init(&fdf);
	if (!parse(argv[1], &fdf) || !fdf.map.h || !fdf.map.w)
		return (ft_printf("Invalid map\n"), graceful_exit(&fdf, 1), 1);
	rot_init(&fdf);
	if (!dis_init(&fdf))
		return (ft_printf("Display init failed\n"), graceful_exit(&fdf, 1), 1);
	render(&fdf);
	mlx_key_hook(fdf.win, on_press, &fdf);
	mlx_hook(fdf.win, 17, 1L << 0, graceful_exit, &fdf);
	mlx_loop(fdf.mlx);
}
