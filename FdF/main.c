/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:18:24 by username          #+#    #+#             */
/*   Updated: 2024/10/22 15:24:45 by username         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	t_point	start = {400, 300};
	(void)argc;
	(void)argv;
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 800, 600, "FdF");
	//draw_line((t_point){ft_atoi(argv[1]), ft_atoi(argv[2])}, (t_point){ft_atoi(argv[3]), ft_atoi(argv[4])}, fdf);
	draw_line(start, (t_point){800, 250}, fdf);
	draw_line(start, (t_point){800, 350}, fdf);
	draw_line(start, (t_point){0, 250}, fdf);
	draw_line(start, (t_point){0, 350}, fdf);
	draw_line(start, (t_point){450, 0}, fdf);
	draw_line((t_point){460,0}, (t_point){410, 300}, fdf);
	draw_line(start, (t_point){350, 0}, fdf);
	draw_line(start, (t_point){450, 600}, fdf);
	draw_line(start, (t_point){350, 600}, fdf);
	draw_line((t_point){0, 0}, (t_point){200, 200}, fdf);
	mlx_key_hook(fdf.win, &on_press, &fdf);
	mlx_loop(fdf.mlx);
}
