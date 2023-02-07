/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:18:57 by stamim            #+#    #+#             */
/*   Updated: 2023/01/17 10:33:16 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_size_t.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	idx;

	idx = 0;
	while (src[idx] && idx < len)
	{
		dst[idx] = src[idx];
		idx++;
	}
	return (dst);
}
