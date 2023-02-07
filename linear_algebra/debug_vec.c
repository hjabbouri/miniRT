/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:21:11 by hjabbour          #+#    #+#             */
/*   Updated: 2023/02/01 19:08:23 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	print_vec(t_vec vec)
{
	printf("vector x: %.5f | y: %.5f | z: %.5f | (w: %.5f)\n", vec.x, vec.y,
		vec.z, vec.w);
}

void	print_clr(t_color clr)
{
	printf("color r: %d | g: %d | b: %d\n", clr.r, clr.g, clr.b);
}

void	print_pnt(t_point pnt)
{
	printf("point x: %.2f | y: %.2f | z: %.2f | (w: %.2f)\n", pnt.x, pnt.y,
		pnt.z, pnt.w);
}

t_color	clr_div_value(t_color vec, float val)
{
	vec.r /= val;
	vec.g /= val;
	vec.b /= val;
	return (vec);
}

t_color	clr_div_clr(t_color vec, t_color val)
{
	vec.r /= val.r;
	vec.g /= val.g;
	vec.b /= val.b;
	return (vec);
}
