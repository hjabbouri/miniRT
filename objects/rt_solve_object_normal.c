/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_solve_object_normal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:38:25 by stamim            #+#    #+#             */
/*   Updated: 2023/02/05 12:10:27 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "enums.h"
#include "macros.h"
#include "types.h"

t_vec	rt_sph_get_normal_at(const t_sph sph, const t_vec pnt)
{
	return (vec_normalize(vec_sub_vec(pnt, sph.c)));
}

t_vec	rt_pln_get_normal_at(const t_pln pln, const t_vec dir)
{
	if (vec_dot_product_vec(dir, vec_add_vec(pln.p, pln.n)) < .0F)
	{
		return (vec_multi_value(pln.n, -1));
	}
	return (pln.n);
	(void)dir;
}

t_vec	rt_cyl_normal_at(const t_cyl cyl, const t_hit hit, const t_ray ray)
{
	t_vec	org;

	org = vec_sub_vec(ray.o, cyl.cnt);
	return (vec_normalize(
			vec_sub_vec(vec_add_vec(vec_multi_value(ray.d, hit.dis), org),
				vec_multi_value(cyl.nrm,
					vec_dot_product_vec(ray.d, cyl.nrm) * hit.dis
					+ vec_dot_product_vec(org, cyl.nrm)))));
}
