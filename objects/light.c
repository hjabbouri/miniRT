/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:19:17 by hjabbour          #+#    #+#             */
/*   Updated: 2023/02/05 15:22:48 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/types.h"
#include "enums.h"
#include "macros.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

t_color	clamp(t_color clr)
{
	if (clr.r > 255)
		clr.r = 255;
	if (clr.r < 0)
		clr.r = 0;
	if (clr.g > 255)
		clr.g = 255;
	if (clr.g < 0)
		clr.g = 0;
	if (clr.b > 255)
		clr.b = 255;
	if (clr.b < 0)
		clr.b = 0;
	return (clr);
}

static bool	is_shadowed(const t_scene *scn, t_vec pnt, const t_obj *jump)
{
	const float	dis = vec_length(vec_sub_vec(scn->light.pos, pnt));
	const t_vec	dir = vec_normalize(vec_sub_vec(scn->light.pos, pnt));
	t_ray		ray;
	t_hit		hit;
	const t_obj	*obj;

	ray.d = vector(dir.x, dir.y, dir.z);
	ray.o = point(pnt.x, pnt.y, pnt.z);
	obj = NULL;
	hit = closest_object(&obj, ray, scn->objs, jump);
	if (!obj)
		return (false);
	if (hit.dis > EPSILON && hit.dis < dis)
		return (true);
	return (false);
	(void)jump;
}

static t_color	diffuse_light(const t_obj *obj, t_light light, float dif_coef)
{
	t_color	clr;

	clr = (t_color){0};
	if (obj->type == SPHERE)
	{
		clr = clr_multi_clr(obj->sph.rgb, light.clr);
	}
	else if (obj->type == PLANE)
	{
		clr = clr_multi_clr(obj->pln.rgb, light.clr);
	}
	else if (obj->type == CYLINDER)
	{
		clr = clr_multi_clr(obj->cyl.rgb, light.clr);
	}
	else if (obj->type == CONE)
	{
		clr = clr_multi_clr(obj->con.rgb, light.clr);
	}
	return (clr_multi_value(clr, dif_coef));
}

static float	the_diffuse_coefficient(const t_ray ray, const t_obj *obj,
	const t_scene *scn, const t_hit hit)
{
	const t_vec		pnt = vec_add_vec(ray.o, vec_multi_value(ray.d, hit.dis));
	const t_vec		light_dir = vec_normalize(vec_sub_vec(scn->light.pos, pnt));
	const t_vec		normal_at = get_normal_at(obj, ray, hit, pnt);
	float			dif_coef;

	dif_coef = vec_dot_product_vec(normal_at, light_dir);
	if (dif_coef < EPSILON)
	{
		if (hit.is_inside == false)
		{
			return (0.0F);
		}
		dif_coef = vec_dot_product_vec(
				vec_multi_value(normal_at, -1), light_dir);
		if (dif_coef < EPSILON)
		{
			return (0.0F);
		}
	}
	return (dif_coef);
}

t_color	light_coloring(const t_ray ray, const t_hit hit,
	const t_scene *scn, const t_obj *obj)
{
	const t_vec		pnt = vec_add_vec(ray.o, vec_multi_value(ray.d, hit.dis));
	t_color			diffuse;
	const t_color	ambient = clr_multi_value(
			clr_multi_clr(scn->amb.la, scn->light.clr), scn->amb.ka);
	float			dif_coef;

	if (is_shadowed(scn, pnt, obj))
		return (ambient);
	dif_coef = the_diffuse_coefficient(ray, obj, scn, hit);
	diffuse = diffuse_light(obj, scn->light, dif_coef);
	return (clr_add_clr(diffuse, ambient));
}
