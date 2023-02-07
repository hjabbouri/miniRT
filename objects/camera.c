/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:21:51 by hjabbour          #+#    #+#             */
/*   Updated: 2023/02/06 11:24:37 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "types.h"
#include "enums.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

static float	half_width(const float aspect, const float half_view)
{
	if (aspect >= 1)
	{
		return (half_view);
	}
	return (half_view * aspect);
}

static float	half_height(const float aspect, const float half_view)
{
	if (aspect >= 1)
	{
		return (half_view / aspect);
	}
	return (half_view);
}

t_matrix_4x4	view_transform(t_vec forward, t_point from, t_vec up)
{
	t_matrix_4x4	mat;
	t_vec			left;
	t_vec			true_up;

	up = vec_normalize(up);
	forward = vec_normalize(forward);
	left = vec_cross_product(forward, up);
	true_up = vec_cross_product(left, forward);
	mat = (t_matrix_4x4){.m = {
	{left.x, left.y, left.z, 0},
	{true_up.x, true_up.y, true_up.z, 0},
	{-forward.x, -forward.y, -forward.z, 0},
	{0, 0, 0, 1},
	}};
	return (matr4x4_multi_matr4x4(mat,
			matr4x4_translation(-from.x, -from.y, -from.z)));
}

static void	up_left_forward(t_vec forward, t_vec up, t_camera *cam)
{
	t_vec	tmp_up;

	tmp_up = vector(0, 1, 0);
	if (is_equal(fabsf(vec_dot_product_vec(forward, tmp_up)), 1))
	{
		tmp_up = vector(0, 0, 1);
	}
	if (is_equal(fabsf(vec_dot_product_vec(forward, tmp_up)), 1))
	{
		tmp_up = vector(1, 0, 0);
	}
	up = vec_normalize(tmp_up);
	cam->forward = vec_normalize(forward);
	cam->left = vec_cross_product(cam->forward, up);
	cam->up = vec_cross_product(cam->left, cam->forward);
}

void	generate_camera(t_scene *scn)
{
	scn->cam.aspect = (float)width / (float)height;
	scn->cam.half_view = tanf(deg_to_rad(scn->cam.fov) / 2);
	scn->cam.half_width = half_width(scn->cam.aspect, scn->cam.half_view);
	scn->cam.half_height = half_height(scn->cam.aspect, scn->cam.half_view);
	scn->cam.pixel_size = (scn->cam.half_width * 2) / (float)width;
	scn->cam.transform = matr4x4_identity();
	up_left_forward(scn->cam.cam_dir, vector(0, 1, 0), &scn->cam);
}
