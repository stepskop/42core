/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:02:43 by username          #+#    #+#             */
/*   Updated: 2024/10/30 01:04:56 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_x(t_fdf *fdf, double angle)
{
	t_matrix	mat;

	mat = (t_matrix){
		1, 0, 0,
		0, cos(angle), -sin(angle),
		0, sin(angle), cos(angle)};
	apply_mat(fdf, mat);
}

void	rot_y(t_fdf *fdf, double angle)
{
	t_matrix	mat;

	mat = (t_matrix){
		cos(angle), 0, sin(angle),
		0, 1, 0,
		-sin(angle), 0, cos(angle)};
	apply_mat(fdf, mat);
}

void	rot_z(t_fdf *fdf, double angle)
{
	t_matrix	mat;

	mat = (t_matrix){
		cos(angle), -sin(angle), 0,
		sin(angle), cos(angle), 0,
		0, 0, 1};
	apply_mat(fdf, mat);
}

void	elev(t_fdf *fdf, double val)
{
	t_matrix	mat;

	mat = (t_matrix){
		1, 0, 0,
		0, 1, 0,
		0, 0, val};
	//reset
	apply_mat(fdf, mat);
	apply_mat(fdf, fdf->cam.back);
}

void	zoom(t_fdf *fdf, double val)
{
	t_matrix	mat;

	mat = (t_matrix){
		val, 0, 0,
		0, val, 0,
		0, 0, val};
	apply_mat(fdf, mat);
}
