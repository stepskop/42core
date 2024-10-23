/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:07:31 by username          #+#    #+#             */
/*   Updated: 2024/10/23 15:37:12 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "libft/libft.h"
# include <X11/keysym.h>
# include "math.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_data
{
	void	*ptr;
	char	*addr;
	int	bbp;
	int	line_len;
	int	endian;
}	t_data;

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_fdf
{
	t_xvar		*mlx;
	t_win_list	*win;
	t_data		img;
	int		map_w;
	int		map_h;
	char		***map;
}	t_fdf;

void	draw_map(t_fdf fdf);

//TEST
void	draw_demo(t_fdf fdf);



//Draw utils
void	put_pixel(t_point pix, t_data data, int color);
void	draw_line(t_point from, t_point to, t_fdf fdf);

//Parse
int	parse(char *file, t_fdf *fdf);
int	is_inrow(char **row, int x);

//Memory
void	free_map(char ***map);

//Lifecycle
int	graceful_exit(t_fdf *fdf);

//Hooks
int	on_press(int k_code, t_fdf *fdf);

#endif
