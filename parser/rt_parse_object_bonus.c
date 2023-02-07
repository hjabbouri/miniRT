/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_object_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:30:45 by stamim            #+#    #+#             */
/*   Updated: 2023/02/04 18:46:55 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "enums.h"
#include "types.h"

void	rt_parse_con(t_scene *scn, char **args)
{
	bool	err;

	err = false;
	scn->objs->con.cnt = rt_get_coordinates(args[2], &err, POINT);
	if (err)
		(rt_destroy_objs(scn), rt_exit("could not parse cone point"));
	scn->objs->con.nrm = rt_get_coordinates(args[3], &err, NORM);
	if (err)
		(rt_destroy_objs(scn), rt_exit("could not parse cone norm"));
	scn->objs->con.hgt = rt_get_val(args[4], &err);
	if (err)
		(rt_destroy_objs(scn), rt_exit("could not parse cone height"));
	scn->objs->con.ang = tanf(rt_get_val(args[5], &err));
	if (err)
		(rt_destroy_objs(scn), rt_exit("could not parse cone angle"));
	scn->objs->con.fac = 1 + powf(scn->objs->con.ang, 2);
	scn->objs->con.rgb = rt_get_color(args[6], &err);
	if (err)
		(rt_destroy_objs(scn), rt_exit("could not parse cone color"));
	if (args[7])
		(rt_destroy_objs(scn), rt_exit("one extra argument on cone"));
}
