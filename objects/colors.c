/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:54:29 by hjabbour          #+#    #+#             */
/*   Updated: 2023/02/05 16:46:59 by hjabbour         ###   ########.fr       */
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

bool	check_rgb(t_color clr)
{
	if (clr.r < 0 || clr.r > 255)
		return (false);
	if (clr.g < 0 || clr.g > 255)
		return (false);
	if (clr.b < 0 || clr.b > 255)
		return (false);
	return (true);
}

bool	check_ratio(float ratio)
{
	if (ratio < 0.0 || ratio > 1.0)
		return (false);
	return (true);
}

bool	accepted_values(const t_scene *scn)
{
	t_obj	*cur_obj;

	if (!check_rgb(scn->amb.la) || !check_rgb(scn->light.clr)
		|| !check_ratio(scn->light.bri) || !check_ratio(scn->amb.ka))
		return (false);
	if (scn->cam.fov < 0 || scn->cam.fov > 180)
		return (false);
	cur_obj = scn->objs;
	while (cur_obj)
	{
		if (cur_obj->type == SPHERE && !check_rgb(cur_obj->sph.rgb))
			return (false);
		if (cur_obj->type == PLANE && !check_rgb(cur_obj->pln.rgb))
			return (false);
		if (cur_obj->type == CYLINDER && !check_rgb(cur_obj->cyl.rgb))
			return (false);
		if (cur_obj->type == CONE && !check_rgb(cur_obj->con.rgb))
			return (false);
		cur_obj = cur_obj->next;
	}
	return (true);
}
