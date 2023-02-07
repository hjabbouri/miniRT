/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:22:22 by hjabbour          #+#    #+#             */
/*   Updated: 2023/02/05 12:41:55 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "types.h"
#include "enums.h"
#include "macros.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

t_vec	get_normal_at(const t_obj *obj, t_ray ray, t_hit hit, const t_point pnt)
{
	t_vec	vec;

	vec = vector(0, 0, 0);
	if (obj->type == SPHERE)
	{
		vec = rt_sph_get_normal_at(obj->sph, pnt);
	}
	else if (obj->type == PLANE)
	{
		vec = rt_pln_get_normal_at(obj->pln, pnt);
	}
	else if (obj->type == CYLINDER)
	{
		vec = rt_cyl_normal_at(obj->cyl, hit, ray);
	}
	else if (obj->type == CONE)
	{
		vec = rt_con_normal_at(obj->con, hit, ray);
	}
	return (vec);
}

t_hit	closest_object(const t_obj **obj, t_ray ray, const t_obj *cur_obj,
	const t_obj *jump)
{
	t_hit	min_hit;
	t_hit	cur_hit;

	min_hit.dis = MAXFLOAT;
	while (cur_obj)
	{
		cur_hit.dis = MAXFLOAT;
		cur_hit.is_inside = false;
		if (cur_obj != jump && cur_obj->type == SPHERE)
			rt_sph_closest_hit(cur_obj->sph, ray, &cur_hit);
		else if (cur_obj != jump && cur_obj->type == PLANE)
			rt_pln_closest_hit(cur_obj->pln, ray, &cur_hit);
		else if (cur_obj != jump && cur_obj->type == CONE)
			rt_con_closest_hit(cur_obj->con, ray, &cur_hit);
		else if (cur_obj != jump && cur_obj->type == CYLINDER)
			rt_cyl_closest_hit(cur_obj->cyl, ray, &cur_hit);
		if (cur_obj != jump && cur_hit.dis > EPSILON
			&& cur_hit.dis < min_hit.dis)
		{
			*obj = cur_obj;
			min_hit = cur_hit;
		}
		cur_obj = cur_obj->next;
	}
	return (min_hit);
}

t_color	objects_coloring(const t_ray ray, const t_scene *scn)
{
	t_hit		hit;
	const t_obj	*the_obj;
	t_color		clr;

	the_obj = NULL;
	hit.dis = -1;
	hit = closest_object(&the_obj, ray, scn->objs, NULL);
	if (!the_obj)
		return ((t_color){0});
	clr = light_coloring(ray, hit, scn, the_obj);
	return (clamp(clr));
}
