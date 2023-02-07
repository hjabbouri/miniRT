/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_solve_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:39:06 by stamim            #+#    #+#             */
/*   Updated: 2023/02/05 12:18:25 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "enums.h"
#include "macros.h"
#include "types.h"
#include <math.h>
#include <stdbool.h>

void	rt_pln_closest_hit(const t_pln pln, const t_ray ray, t_hit *const hit)
{
	const float	den = vec_dot_product_vec(ray.d, pln.n);
	const t_vec	org = vec_sub_vec(ray.o, pln.p);

	hit->is_inside = true;
	if (den != .0F)
	{
		hit->dis = -vec_dot_product_vec(org, pln.n) / den;
		return ;
	}
	hit->dis = -1;
}

t_qud	rt_sol_qua_eq(const float cf1, const float cf2, const float cf3)
{
	const float	dis = powf(cf2, 2) - 4 * cf1 * cf3;
	float		den;
	float		sqr;
	t_qud		sol;

	if (dis == .0F)
	{
		sol.count = 1;
		sol.sl1 = -cf2 / (2 * cf1);
		return (sol);
	}
	if (dis > .0F)
	{
		sol.count = 2;
		sqr = sqrtf(dis);
		den = 2 * cf1;
		sol.sl1 = (-cf2 - sqr) / den;
		sol.sl2 = (-cf2 + sqr) / den;
		return (sol);
	}
	sol.count = 0;
	return (sol);
}

void	rt_sph_closest_hit(const t_sph sph, const t_ray ray, t_hit *const hit)
{
	const t_vec	org = vec_sub_vec(ray.o, sph.c);
	const t_qud	sol = rt_sol_qua_eq(vec_dot_product(ray.d),
			2 * vec_dot_product_vec(ray.d, org),
			vec_dot_product(org) - sph.sq_r);

	if (sol.count == 2 && sol.sl1 < EPSILON && sol.sl2 > EPSILON)
		hit->is_inside = true;
	if (sol.count == 1 && sol.sl1 > EPSILON && sol.sl1 < hit->dis)
	{
		hit->dis = sol.sl1;
	}
	else if (sol.count == 2 && sol.sl1 > EPSILON && sol.sl1 < hit->dis)
	{
		hit->dis = sol.sl1;
	}
	else if (sol.count == 2 && sol.sl2 > EPSILON && sol.sl2 < hit->dis)
	{
		hit->dis = sol.sl2;
	}
	else
	{
		hit->dis = -1;
	}
}

void	rt_cyl_closest_hit(const t_cyl cyl, const t_ray ray, t_hit *const hit)
{
	const t_vec	org = vec_sub_vec(ray.o, cyl.cnt);
	const float	dpt[2] = {vec_dot_product_vec(ray.d, cyl.nrm),
		vec_dot_product_vec(org, cyl.nrm)};
	const t_qud	sol = rt_sol_qua_eq(vec_dot_product(ray.d) - powf(dpt[0], 2),
			2 * (vec_dot_product_vec(ray.d, org) - dpt[0] * dpt[1]),
			vec_dot_product_vec(org, org) - powf(dpt[1], 2) - cyl.rd2);

	if (sol.count == 2 && sol.sl1 < EPSILON && sol.sl2 > EPSILON)
		hit->is_inside = true;
	if (sol.count == 1 && sol.sl1 > EPSILON && sol.sl1 < hit->dis
		&& dpt[0] * sol.sl1 + dpt[1] >= -cyl.hgt / 2
		&& dpt[0] * sol.sl1 + dpt[1] <= cyl.hgt / 2)
			hit->dis = sol.sl1;
	else if (sol.count == 2 && sol.sl1 > EPSILON && sol.sl1 < hit->dis
		&& dpt[0] * sol.sl1 + dpt[1] >= -cyl.hgt / 2
		&& dpt[0] * sol.sl1 + dpt[1] <= cyl.hgt / 2)
			hit->dis = sol.sl1;
	else if (sol.count == 2 && sol.sl2 > EPSILON && sol.sl2 < hit->dis
		&& dpt[0] * sol.sl2 + dpt[1] >= -cyl.hgt / 2
		&& dpt[0] * sol.sl2 + dpt[1] <= cyl.hgt / 2)
			hit->dis = sol.sl2;
	else
		hit->dis = -1;
}
