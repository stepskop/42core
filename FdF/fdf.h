/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:07:31 by username          #+#    #+#             */
/*   Updated: 2024/10/22 13:36:39 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "libft/libft.h"
# include <X11/keysym.h>
# include "math.h"

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_fdf
{
	t_xvar		*mlx;
	t_win_list	*win;
}	t_fdf;

//Draw
void	draw_line(t_point from, t_point to, t_fdf fdf);

#endif
