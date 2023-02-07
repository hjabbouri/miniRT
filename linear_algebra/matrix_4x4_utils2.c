/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4x4_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:13:30 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/16 10:54:07 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_matrix_4x4	matr4x4_transpos(t_matrix_4x4 mat)
{
	int		rows;
	int		cols;
	float	tmp;

	rows = 0;
	while (rows < 4)
	{
		cols = rows + 1;
		while (cols < 4)
		{
			tmp = mat.m[rows][cols];
			mat.m[rows][cols] = mat.m[cols][rows];
			mat.m[cols][rows] = tmp;
			cols++;
		}
		rows++;
	}
	return (mat);
}

t_matrix_3x3	sub_matr4x4(t_matrix_4x4 mat, int row, int col)
{
	t_matrix_3x3	ret;
	int				rows;
	int				cols;
	float			iidx;
	int				jidx;

	rows = 0;
	iidx = 0;
	while (rows < 4)
	{
		cols = 0;
		jidx = 0;
		while (cols < 4 && rows != row)
		{
			if (cols != col && rows != row)
			{
				ret.m[(int)iidx][jidx] = mat.m[rows][cols];
				jidx++;
			}
			iidx += 0.25;
			cols++;
		}
		rows++;
	}
	return (ret);
}
