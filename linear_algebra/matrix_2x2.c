/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2x2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:00:14 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/16 10:52:43 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	print_matr2x2(t_matrix_2x2 mat)
{
	int	rows;

	rows = 0;
	while (rows < 2)
	{
		printf("| %f | %f |\n", mat.m[rows][0], mat.m[rows][1]);
		rows++;
	}
}

float	determ_matr2x2(t_matrix_2x2 mat)
{
	return ((mat.m[0][0] * mat.m[1][1]) - (mat.m[0][1] * mat.m[1][0]));
}

bool	is_invertible2x2(t_matrix_2x2 mat)
{
	return (determ_matr2x2(mat) != 0);
}
