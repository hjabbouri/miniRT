/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:46:36 by stamim            #+#    #+#             */
/*   Updated: 2023/02/05 13:13:43 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "enums.h"
#include "types.h"
#include <stdbool.h>
#include <stdlib.h>

static void	rt_parse_sph(t_scene *scn, char **args)
{
	bool	err;

	err = false;
	scn->objs->sph.c = rt_get_coordinates(args[2], &err, POINT);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse the sphere coordinates");
	}
	scn->objs->sph.sq_r = powf(rt_get_val(args[3], &err), 2);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse the sphere diameter");
	}
	scn->objs->sph.rgb = rt_get_color(args[4], &err);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse the sphere coordinates");
	}
	if (args[5])
		(rt_destroy_objs(scn), rt_exit("one extra argument on sphere"));
}

static void	rt_parse_pln(t_scene *scn, char **args)
{
	bool	err;

	err = false;
	scn->objs->pln.p = rt_get_coordinates(args[2], &err, POINT);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse the plane point coordinates");
	}
	scn->objs->pln.n = rt_get_coordinates(args[3], &err, NORM);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse the plane normal coordinates");
	}
	scn->objs->pln.rgb = rt_get_color(args[4], &err);
	if (err)
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse the plane color coordinates");
	}
	if (args[5])
		(rt_destroy_objs(scn), rt_exit("one extra argument on plane"));
}

static void	rt_parse_cyl(t_scene *scn, char **args)
{
	bool	err;

	err = false;
	scn->objs->cyl.cnt = rt_get_coordinates(args[2], &err, POINT);
	if (err)
		(rt_destroy_objs(scn),
			rt_exit("could not parse the cylinder coordinates"));
	scn->objs->cyl.nrm = rt_get_coordinates(args[3], &err, NORM);
	if (err)
		(rt_destroy_objs(scn),
			rt_exit("could not parse the cylinder normal coordinates"));
	scn->objs->cyl.rd2 = powf(rt_get_val(args[4], &err) / 2, 2);
	if (err)
		(rt_destroy_objs(scn),
			rt_exit("could not parse the cylinder diameter"));
	scn->objs->cyl.hgt = rt_get_val(args[5], &err);
	if (err)
		(rt_destroy_objs(scn),
			rt_exit("could not parse the cylinder height"));
	scn->objs->cyl.rgb = rt_get_color(args[6], &err);
	if (err)
		(rt_destroy_objs(scn),
			rt_exit("could not parse the cylinder color coordinates"));
	if (args[7])
		(rt_destroy_objs(scn), rt_exit("one extra argument on cylinder"));
}

static void	rt_new_obj(t_scene *scn, const int type, char **args)
{
	t_obj *const	head = scn->objs;
	t_obj *const	obj = (t_obj *)malloc(sizeof(t_obj));

	if (!obj)
	{
		rt_destroy_objs(scn);
		exit(EXIT_FAILURE);
	}
	obj->type = type;
	obj->next = head;
	scn->objs = obj;
	if (type == SPHERE)
		rt_parse_sph(scn, args);
	else if (type == PLANE)
		rt_parse_pln(scn, args);
	else if (type == CYLINDER)
		rt_parse_cyl(scn, args);
	else if (type == CONE)
		rt_parse_con(scn, args);
}

void	rt_parse_obj(t_scene *scn, char **args)
{
	if (!ft_strcmp(args[1], "sp"))
		rt_new_obj(scn, SPHERE, args);
	else if (!ft_strcmp(args[1], "pl"))
		rt_new_obj(scn, PLANE, args);
	else if (!ft_strcmp(args[1], "cy"))
		rt_new_obj(scn, CYLINDER, args);
	else if (!ft_strcmp(args[1], "cn"))
		rt_new_obj(scn, CONE, args);
	else
	{
		rt_destroy_objs(scn);
		rt_exit("could not parse a line");
	}
}
