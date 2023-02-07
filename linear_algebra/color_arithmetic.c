/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_arithmetic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:06:51 by hjabbour          #+#    #+#             */
/*   Updated: 2023/02/05 13:21:41 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_color	clr_add_value(t_color vec, float val)
{
	vec.r += val;
	vec.g += val;
	vec.b += val;
	return (vec);
}

t_color	clr_add_clr(t_color vec, t_color val)
{
	vec.r += val.r;
	vec.g += val.g;
	vec.b += val.b;
	return (vec);
}

t_color	clr_multi_value(t_color vec, float val)
{
	vec.r *= val;
	vec.g *= val;
	vec.b *= val;
	return (vec);
}

t_color	clr_multi_clr(t_color vec, t_color val)
{
	vec.r *= (val.r / 255);
	vec.g *= (val.g / 255);
	vec.b *= (val.b / 255);
	return (vec);
}

int	generate_color(t_color clr)
{
	return ((clr.r << 16) | (clr.g << 8) | clr.b);
}
