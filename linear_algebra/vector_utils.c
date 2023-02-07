/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:59:01 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/24 11:02:21 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_point	point(const float x, const float y, const float z)
{
	return ((t_point){x, y, z, 1});
}

t_vec	vector(const float x, const float y, const float z)
{
	return ((t_vec){x, y, z, 0});
}
