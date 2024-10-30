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
}
