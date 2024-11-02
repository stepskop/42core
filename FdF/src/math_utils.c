/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:40:44 by username          #+#    #+#             */
/*   Updated: 2024/10/30 00:53:27 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	apply_one(t_point *point, t_matrix mat)
{
	t_point	tmp;

	tmp = *point;
	point->x = tmp.x * mat.r1c1 + tmp.y * mat.r1c2 + tmp.z * mat.r1c3;
	point->y = tmp.x * mat.r2c1 + tmp.y * mat.r2c2 + tmp.z * mat.r2c3;
	point->z = tmp.x * mat.r3c1 + tmp.y * mat.r3c2 + tmp.z * mat.r3c3;
}

t_point	v_add(t_point a, t_point b)
{
	t_point	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	res.color = a.color;
	return (res);
}

t_point	v_sub(t_point a, t_point b)
{
	t_point	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	res.color = a.color;
	return (res);
}

// static t_matrix	mat_mult(t_matrix a, t_matrix b)
// {
// 	t_matrix	res;
//
// 	res.r1c1 = a.r1c1 * b.r1c1 + a.r1c2 * b.r2c1 + a.r1c3 * b.r3c1;
// 	res.r1c2 = a.r2c1 * b.r1c1 + a.r2c2 * b.r2c1 + a.r2c3 * b.r3c1;
// 	res.r1c3 = a.r3c1 * b.r1c1 + a.r3c2 * b.r2c1 + a.r3c3 * b.r3c1;
// 	res.r2c1 = a.r1c1 * b.r1c2 + a.r1c2 * b.r2c2 + a.r1c3 * b.r3c2;
// 	res.r2c2 = a.r2c1 * b.r1c2 + a.r2c2 * b.r2c2 + a.r2c3 * b.r3c2;
// 	res.r2c3 = a.r3c1 * b.r1c2 + a.r3c2 * b.r2c2 + a.r3c3 * b.r3c2;
// 	res.r3c1 = a.r1c1 * b.r1c3 + a.r1c3 * b.r2c3 + a.r1c3 * b.r3c3;
// 	res.r3c2 = a.r2c1 * b.r1c3 + a.r2c3 * b.r2c3 + a.r2c3 * b.r3c3;
// 	res.r3c3 = a.r3c1 * b.r1c3 + a.r3c3 * b.r2c3 + a.r3c3 * b.r3c3;
// 	return (res);
// }

static t_matrix mat_mult(t_matrix a, t_matrix b)
{
    t_matrix res;

    res.r1c1 = a.r1c1 * b.r1c1 + a.r1c2 * b.r2c1 + a.r1c3 * b.r3c1;
    res.r1c2 = a.r1c1 * b.r1c2 + a.r1c2 * b.r2c2 + a.r1c3 * b.r3c2;
    res.r1c3 = a.r1c1 * b.r1c3 + a.r1c2 * b.r2c3 + a.r1c3 * b.r3c3;

    res.r2c1 = a.r2c1 * b.r1c1 + a.r2c2 * b.r2c1 + a.r2c3 * b.r3c1;
    res.r2c2 = a.r2c1 * b.r1c2 + a.r2c2 * b.r2c2 + a.r2c3 * b.r3c2;
    res.r2c3 = a.r2c1 * b.r1c3 + a.r2c2 * b.r2c3 + a.r2c3 * b.r3c3;

    res.r3c1 = a.r3c1 * b.r1c1 + a.r3c2 * b.r2c1 + a.r3c3 * b.r3c1;
    res.r3c2 = a.r3c1 * b.r1c2 + a.r3c2 * b.r2c2 + a.r3c3 * b.r3c2;
    res.r3c3 = a.r3c1 * b.r1c3 + a.r3c2 * b.r2c3 + a.r3c3 * b.r3c3;

    return res;
}


void	apply_mat(t_fdf *fdf, t_matrix mat)
{
	int		i;
	int		j;

	i = -1;
	while (fdf->map.pts[++i])
	{
		j = -1;
		while (fdf->map.pts[i][++j])
			apply_one(fdf->map.pts[i][j], mat);
	}
	fdf->cam.back = mat_mult(fdf->cam.back, mat);
}
