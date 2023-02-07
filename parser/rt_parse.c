/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:21:26 by stamim            #+#    #+#             */
/*   Updated: 2023/02/05 12:23:46 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declarations.h"
#include "types.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static bool	rt_is_space(const char chr)
{
	return (chr == ' ' || (chr >= '\t' && chr <= '\r'));
}

static size_t	rt_arg_cnt(const char *line)
{
	size_t	count;

	count = 0;
	while (*line)
	{
		if (rt_is_space(*line))
		{
			line++;
			while (rt_is_space(*line))
			{
				line++;
			}
		}
		else
		{
			count++;
			line++;
			while (*line && !rt_is_space(*line))
			{
				line++;
			}
		}
	}
	return (count);
}

static char	**rt_split(char *line)
{
	char	**args;
	size_t	idx;
	size_t	len;

	len = rt_arg_cnt(line);
	args = (char **)malloc(sizeof(char *) * (len + 2));
	args[0] = line;
	idx = 1;
	while (idx <= len)
	{
		while (rt_is_space(*line))
			line++;
		args[idx++] = line;
		while (*line && !rt_is_space(*line))
			line++;
		if (*line == '\0')
			break ;
		*line = '\0';
		line++;
		while (rt_is_space(*line))
			line++;
	}
	args[idx] = NULL;
	return (args);
}

static bool	rt_getline(char **const line, const int file, t_scene *const scn)
{
	char	*tmp;
	size_t	len;
	int		bytes;

	*line = (char *)malloc(sizeof(char));
	if (!*line)
		return (rt_destroy_objs(scn), false);
	bytes = read(file, *line, sizeof(char));
	if (bytes == 0)
		return (free(*line), false);
	else if (bytes == -1)
		return (free(*line), rt_destroy_objs(scn), false);
	len = 0;
	while ((*line)[len] != '\n')
	{
		tmp = *line;
		*line = (char *)malloc((++len + 1) * sizeof(char));
		if (!*line)
			return (free(tmp), rt_destroy_objs(scn), false);
		ft_strncpy(*line, tmp, len);
		free(tmp);
		if (read(file, *line + len, sizeof(char)) <= 0)
			break ;
	}
	return ((*line)[len] = '\0', true);
}

void	rt_parse(t_scene *const scn, const int file, char *line)
{
	char	**args;

	while (rt_getline(&line, file, scn))
	{
		args = rt_split(line);
		if (args[1])
		{
			if (!ft_strcmp(args[1], "A"))
				rt_parse_amb(scn, args);
			else if (!ft_strcmp(args[1], "C"))
				rt_parse_cam(scn, args);
			else if (!ft_strcmp(args[1], "L"))
				rt_parse_light(scn, args);
			else if (ft_strcmp(args[1], "#"))
				rt_parse_obj(scn, args);
		}
		free(args[0]);
		free(args);
	}
}
