/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4x4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:01:03 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/24 13:49:05 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "declarations.h"

t_matrix_4x4	matr4x4_multi_matr4x4(t_matrix_4x4 mat1, t_matrix_4x4 mat2)
{
	int				rows;
	int				cols;
	t_matrix_4x4	mat;

	rows = 0;
	while (rows < 4)
	{
		cols = 0;
		while (cols < 4)
		{
			mat.m[rows][cols] = (mat1.m[rows][0] * mat2.m[0][cols])
				+ (mat1.m[rows][1] * mat2.m[1][cols])
				+ (mat1.m[rows][2] * mat2.m[2][cols])
				+ (mat1.m[rows][3] * mat2.m[3][cols]);
			cols++;
		}
		rows++;
	}
	return (mat);
}

t_tuple	matr4x4_multi_tuple(t_matrix_4x4 mat, t_tuple tup)
{
	t_tuple	ret;

	ret.x = (mat.m[0][0] * tup.x)
		+ (mat.m[0][1] * tup.y)
		+ (mat.m[0][2] * tup.z)
		+ (mat.m[0][3] * tup.w);
	ret.y = (mat.m[1][0] * tup.x)
		+ (mat.m[1][1] * tup.y)
		+ (mat.m[1][2] * tup.z)
		+ (mat.m[1][3] * tup.w);
	ret.z = (mat.m[2][0] * tup.x)
		+ (mat.m[2][1] * tup.y)
		+ (mat.m[2][2] * tup.z)
		+ (mat.m[2][3] * tup.w);
	ret.w = (mat.m[3][0] * tup.x)
		+ (mat.m[3][1] * tup.y)
		+ (mat.m[3][2] * tup.z)
		+ (mat.m[3][3] * tup.w);
	return (ret);
}

t_vec	matr4x4_multi_vec(t_matrix_4x4 mat, t_vec vec)
{
	t_vec	ret;

	ret.x = (mat.m[0][0] * vec.x)
		+ (mat.m[0][1] * vec.y)
		+ (mat.m[0][2] * vec.z)
		+ (mat.m[0][3] * vec.w);
	ret.y = (mat.m[1][0] * vec.x)
		+ (mat.m[1][1] * vec.y)
		+ (mat.m[1][2] * vec.z)
		+ (mat.m[1][3] * vec.w);
	ret.z = (mat.m[2][0] * vec.x)
		+ (mat.m[2][1] * vec.y)
		+ (mat.m[2][2] * vec.z)
		+ (mat.m[2][3] * vec.w);
	ret.w = (mat.m[3][0] * vec.x)
		+ (mat.m[3][1] * vec.y)
		+ (mat.m[3][2] * vec.z)
		+ (mat.m[3][3] * vec.w);
	return (vector(ret.x, ret.y, ret.z));
}

t_point	matr4x4_multi_point(t_matrix_4x4 mat, t_point pnt)
{
	t_point	ret;

	ret.x = (mat.m[0][0] * pnt.x)
		+ (mat.m[0][1] * pnt.y)
		+ (mat.m[0][2] * pnt.z)
		+ (mat.m[0][3] * pnt.w);
	ret.y = (mat.m[1][0] * pnt.x)
		+ (mat.m[1][1] * pnt.y)
		+ (mat.m[1][2] * pnt.z)
		+ (mat.m[1][3] * pnt.w);
	ret.z = (mat.m[2][0] * pnt.x)
		+ (mat.m[2][1] * pnt.y)
		+ (mat.m[2][2] * pnt.z)
		+ (mat.m[2][3] * pnt.w);
	ret.w = (mat.m[3][0] * pnt.x)
		+ (mat.m[3][1] * pnt.y)
		+ (mat.m[3][2] * pnt.z)
		+ (mat.m[3][3] * pnt.w);
	return (point(ret.x, ret.y, ret.z));
}
