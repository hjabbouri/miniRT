/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:21:01 by stamim            #+#    #+#             */
/*   Updated: 2023/02/05 12:08:06 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "macros.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	rt_exit(const char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str) * sizeof(char));
	write(STDERR_FILENO, "\n", sizeof(char));
	exit(EXIT_FAILURE);
}

void	rt_destroy_objs(t_scene *const scn)
{
	t_obj	*tmp;

	while (scn->objs)
	{
		tmp = scn->objs;
		scn->objs = scn->objs->next;
		free(tmp);
	}
}

int	rt_open(int argc, const char *arg)
{
	int		file;
	size_t	len;

	if (argc != 2)
	{
		rt_exit(INVLD_ARG);
	}
	len = 0;
	while (arg[len])
	{
		len++;
	}
	if (len <= 3 || arg[len - 3] != '.' || arg[len - 2] != 'r'
		|| arg[len - 1] != 't')
	{
		rt_exit(INVLD_FILE);
	}
	file = open(arg, O_CLOEXEC, S_IRUSR);
	if (file == -1)
	{
		perror("open");
		rt_exit(INVLD_ARG);
	}
	return (file);
}
