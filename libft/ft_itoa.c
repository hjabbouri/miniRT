/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:37:43 by hjabbour          #+#    #+#             */
/*   Updated: 2023/01/07 18:35:53 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	void	print_nb(char *s, long ln, int len)
{
	if (ln < 0)
	{
		s[0] = '-';
		ln = ln * (-1);
	}
	s[len--] = '\0';
	if (ln == 0)
		s[0] = 48;
	while (ln != 0)
	{
		s[len--] = (ln % 10) + 48;
		ln /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*s;
	long	ln;

	len = 0;
	ln = n;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	if (ln == 0)
		len = 1;
	else if (ln < 0)
		len++;
	s = malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	print_nb(s, ln, len);
	return (s);
}
