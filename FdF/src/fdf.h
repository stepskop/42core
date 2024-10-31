/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:07:31 by username          #+#    #+#             */
/*   Updated: 2024/10/30 22:48:14 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include "math.h"
# include <stdio.h>

# define WIDTH 1280
# define HEIGHT 720
# define TOP_COLOR 0xD11F40
# define BOT_COLOR 0x4637A3

typedef struct s_data
{
	void	*ptr;
	char	*addr;
	int		bbp;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_matrix
{
	double	r1c1;
	double	r1c2;
	double	r1c3;
	double	r2c1;
	double	r2c2;
	double	r2c3;
	double	r3c1;
	double	r3c2;
	double	r3c3;
}	t_matrix;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_camera
{
	double		elev;
	t_matrix	back;
	t_point		offs;
}	t_camera;

typedef struct s_map
{
	int		w;
	int		h;
	char	***raw;
	t_point	***pts;
	t_point	max;
	t_point	min;
	int		cust_c;
}	t_map;

typedef struct s_fdf
{
	t_xvar		*mlx;
	t_win_list	*win;
	t_data		img;
	t_camera	cam;
	t_map		map;
}	t_fdf;

//Main
void	proj_iso(t_fdf *fdf);
void	render(t_fdf *fdf);

//Draw utils
void	put_pixel(t_point pix, t_data data);
void	draw_line(t_point from, t_point to, t_fdf fdf);

//Coloring
int	get_current_color(t_point start, t_point end, t_point current);

//Parse
int		parse(char *file, t_fdf *fdf);
size_t	line_len(char **line);
int		add_str(t_fdf *fdf, char *line, size_t *i);
int		add_pt(t_fdf *fdf, int i, int j);
void	set_z(int curr, t_fdf *fdf);
int		set_color(int z, t_map map);
int		gradient(int start, int end, int len, int curr);
//Lifecycle
int		graceful_exit(t_fdf *fdf);
void	free_map(char ***map);
void	free_pts(t_point ***arr);
void	finish_read(int fd);

//Hooks
int		on_press(int k_code, t_fdf *fdf);

//Math
void	apply_mat(t_fdf *fdf, t_matrix mat);
t_point	v_add(t_point a, t_point b);
t_point	v_sub(t_point a, t_point b);

//Matrices
void	rot_x(t_fdf *fdf, double angle);
void	rot_y(t_fdf *fdf, double angle);
void	zoom(t_fdf *fdf, double val);
void	move(t_fdf *fdf, t_point off);
void	elev(t_fdf *fdf, double val);

#endif
