/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_solve_object_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:56:17 by stamim            #+#    #+#             */
/*   Updated: 2023/02/05 12:18:40 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "macros.h"
#include "types.h"

void	rt_con_closest_hit(const t_con con, const t_ray ray, t_hit *const hit)
{
	const t_vec	org = vec_sub_vec(ray.o, con.cnt);
	const float	dpa = vec_dot_product_vec(ray.d, con.nrm);
	const float	dpb = vec_dot_product_vec(org, con.nrm);
	const t_qud	sol = rt_sol_qua_eq(
			vec_dot_product(ray.d) - con.fac * powf(dpa, 2),
			2 * (vec_dot_product_vec(ray.d, org) - con.fac * dpa * dpb),
			vec_dot_product(org) - con.fac * powf(dpb, 2));

	if (sol.count == 2 && sol.sl1 < EPSILON && sol.sl2 > EPSILON)
		hit->is_inside = true;
	if (sol.count == 1 && sol.sl1 > EPSILON && sol.sl1 < hit->dis
		&& dpa * sol.sl1 + dpb >= -con.hgt
		&& dpa * sol.sl1 + dpb <= .0F)
			hit->dis = sol.sl1;
	else if (sol.count == 2 && sol.sl1 > EPSILON && sol.sl1 < hit->dis
		&& dpa * sol.sl1 + dpb >= -con.hgt
		&& dpa * sol.sl1 + dpb <= .0F)
			hit->dis = sol.sl1;
	else if (sol.count == 2 && sol.sl2 > EPSILON && sol.sl2 < hit->dis
		&& dpa * sol.sl2 + dpb >= -con.hgt
		&& dpa * sol.sl2 + dpb <= .0F)
			hit->dis = sol.sl2;
	else
		hit->dis = -1;
}
