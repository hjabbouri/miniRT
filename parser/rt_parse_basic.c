/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:42:26 by stamim            #+#    #+#             */
/*   Updated: 2023/02/05 13:12:47 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "enums.h"
#include <stdbool.h>
#include <stdlib.h>

void	rt_parse_light(t_scene *scn, char **args)
{
	bool		err;
	static bool	full = false;

	scn->is_light = true;
	err = false;
	if (full)
	{
		rt_destroy_objs(scn);
		rt_exit("light point cannot be present twice");
	}
	scn->light.pos = rt_get_coordinates(args[2], &err, POINT);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse light point coordinates");
	}
	scn->light.bri = rt_get_val(args[3], &err);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse light point brightness");
	}
	scn->light.clr = rt_get_color(args[4], &err);
	if (args[5])
		(rt_destroy_objs(scn), rt_exit("one extra argument on light"));
}

void	rt_parse_amb(t_scene *scn, char **args)
{
	bool		err;
	static bool	full = false;

	scn->is_amb = true;
	err = false;
	if (full)
	{
		rt_destroy_objs(scn);
		rt_exit("ambient light cannot be present twice");
	}
	full = true;
	scn->amb.ka = rt_get_val(args[2], &err);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse ambient light coefficient");
	}
	scn->amb.la = rt_get_color(args[3], &err);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse ambient light color");
	}
	if (args[4])
		(rt_destroy_objs(scn), rt_exit("one extra argument on ambient"));
}

void	rt_parse_cam(t_scene *scn, char **args)
{
	bool		err;
	static bool	full = false;

	scn->is_cam = true;
	err = false;
	if (full)
		(rt_destroy_objs(scn),
			rt_exit("camera cannot be present twice"));
	full = true;
	scn->cam.cam_ori = rt_get_coordinates(args[2], &err, POINT);
	if (err)
		(rt_destroy_objs(scn),
			rt_exit("could not parse camera origin coordinates"));
	scn->cam.cam_dir = rt_get_coordinates(args[3], &err, NORM);
	if (err)
		(rt_destroy_objs(scn),
			rt_exit("could not parse camera normal coordinates"));
	scn->cam.fov = rt_get_val(args[4], &err);
	if (err)
		(rt_destroy_objs(scn),
			rt_exit("could not parse camera field of view"));
	if (args[5])
		(rt_destroy_objs(scn), rt_exit("one extra argument on camera"));
	generate_camera(scn);
}
