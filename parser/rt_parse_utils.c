/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:30:53 by stamim            #+#    #+#             */
/*   Updated: 2023/02/03 14:44:54 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "enums.h"
#include "types.h"
#include <math.h>
#include <stdbool.h>

t_color	rt_get_color(char *color, bool *const err)
{
	t_color	rgb;

	rgb.r = 0;
	if (!color)
		return (*err = true, rgb);
	while (ft_isdigit(*color))
		rgb.r = rgb.r * 10 + *color++ - '0';
	if (*color == ',')
		color++;
	else
		return (*err = true, rgb);
	rgb.g = 0;
	while (ft_isdigit(*color))
		rgb.g = rgb.g * 10 + *color++ - '0';
	if (*color == ',')
		color++;
	else
		return (*err = true, rgb);
	rgb.b = 0;
	while (ft_isdigit(*color))
		rgb.b = rgb.b * 10 + *color++ - '0';
	if (*color)
		return (*err = true, rgb);
	return (rgb);
}

static float	rt_get_coordinate_val(char **num)
{
	float	val;
	size_t	idx;
	bool	sign;

	idx = 0;
	val = 0;
	sign = false;
	if (**num == '+')
		*num += 1;
	else if (**num == '-')
		*num += ++sign;
	while (ft_isdigit(**num))
		val = val * 10 + *(*num)++ - '0';
	*num += **num == '.';
	while (ft_isdigit((*num)[idx]))
	{
		val += ((*num)[idx] - '0') / pow(10, idx + 1);
		idx++;
	}
	*num += idx;
	if (sign)
		return (-val);
	return (val);
}

t_vec	rt_get_coordinates(char *name, bool *const err, const int type)
{
	t_vec	vec;

	vec.w = 0;
	if (type == POINT)
		vec.w = 1;
	if (!name)
		return (*err = true, vec);
	vec.x = rt_get_coordinate_val(&name);
	if (*name != ',')
		return (*err = true, vec);
	name++;
	vec.y = rt_get_coordinate_val(&name);
	if (*name != ',')
		return (*err = true, vec);
	name++;
	vec.z = rt_get_coordinate_val(&name);
	if (*name)
		return (*err = true, vec);
	if (type == NORM && !is_equal(vec_length(vec), 1.0F))
	{
		vec = vec_normalize(vec);
		printf("non normalized vec, here is a normalized one: x = %f; y = %f; "
			"z = %f\n", vec.x, vec.y, vec.z);
	}
	return (vec);
}

float	rt_get_val(char *num, bool *const err)
{
	float	coef;
	size_t	idx;

	if (!num)
		return (*err = true, 0);
	idx = 0;
	coef = 0;
	if (!ft_isdigit(*num))
		return (*err = true, 0);
	while (ft_isdigit(*num))
	{
		coef = coef * 10 + *num++ - '0';
	}
	if (*num == '.')
		num += 1;
	else if (*num)
		return (*err = true, 0);
	while (ft_isdigit(num[idx]))
	{
		coef += (num[idx] - '0') / pow(10, idx + 1);
		idx++;
	}
	if (num[idx])
		return (*err = true, 0);
	return (coef);
}
