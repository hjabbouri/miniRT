/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:10:47 by stamim            #+#    #+#             */
/*   Updated: 2023/01/19 18:32:21 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_size_t.h>

// TODO(H-J): strncmp
int	ft_strcmp(const char *const str, const char *const to_cmp)
{
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	while (str[len1] && to_cmp[len2] && str[len1] == to_cmp[len2])
	{
		len1++;
		len2++;
	}
	return (str[len1] - to_cmp[len2]);
}
