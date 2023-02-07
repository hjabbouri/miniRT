/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:26:44 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/19 18:45:07 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

float	vec_length(const t_vec vec)
{
	return (sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

t_vec	vec_normalize(t_vec vec)
{
	const float	length = vec_length(vec);
	float		invers;

	if (length > 0)
	{
		invers = 1 / length;
		vec.x *= invers;
		vec.y *= invers;
		vec.z *= invers;
	}
	return (vec);
}

float	vec_dot_product(const t_vec vec)
{
	return ((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

float	vec_dot_product_vec(const t_vec vec1, const t_vec vec2)
{
	return ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
}

t_vec	vec_cross_product(const t_vec first, const t_vec second)
{
	return ((t_vec){
		.x = (first.y * second.z) - (first.z * second.y),
		.y = (first.z * second.x) - (first.x * second.z),
		.z = (first.x * second.y) - (first.y * second.x),
		.w = 0
	});
}
