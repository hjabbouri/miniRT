/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_solve_object_normal_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:57:34 by stamim            #+#    #+#             */
/*   Updated: 2023/02/05 12:20:58 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "types.h"

t_vec	rt_con_normal_at(const t_con con, const t_hit hit, const t_ray ray)
{
	t_vec	org;

	org = vec_sub_vec(ray.o, con.cnt);
	return (vec_normalize(
			vec_sub_vec(vec_add_vec(vec_multi_value(ray.d, hit.dis), org),
				vec_multi_value(con.nrm, con.fac * (
						vec_dot_product_vec(ray.d, con.nrm) * hit.dis
						+ vec_dot_product_vec(org, con.nrm))))));
}
