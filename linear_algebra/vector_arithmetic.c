/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:06:39 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/16 10:51:37 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_vec	vec_add_value(t_vec vec, float val)
{
	vec.x += val;
	vec.y += val;
	vec.z += val;
	return (vec);
}

t_vec	vec_add_vec(t_vec vec, t_vec val)
{
	vec.x += val.x;
	vec.y += val.y;
	vec.z += val.z;
	return (vec);
}

t_vec	vec_sub_value(t_vec vec, float val)
{
	vec.x -= val;
	vec.y -= val;
	vec.z -= val;
	return (vec);
}

t_vec	vec_sub_vec(t_vec vec, t_vec val)
{
	vec.x -= val.x;
	vec.y -= val.y;
	vec.z -= val.z;
	return (vec);
}
