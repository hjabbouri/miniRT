/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3x3_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:20:02 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/16 10:54:40 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "declarations.h"

bool	is_invertible3x3(t_matrix_3x3 mat)
{
	return (determ_matr3x3(mat) != 0);
}
