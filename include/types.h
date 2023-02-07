/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:30:18 by stamim            #+#    #+#             */
/*   Updated: 2023/02/05 12:06:44 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "enums.h"
# include <fcntl.h>
// # include <mlx.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef enum e_keycode	t_keycode;
typedef float			t_deg;
typedef float			t_rad;
typedef t_vec			t_point;
typedef t_vec			t_tuple;
typedef uint32_t		t_buf[height][width];

typedef struct s_sol
{
	int		count;
	float	sl1;
	float	sl2;
}	t_qud;

typedef struct s_hit
{
	float	dis;
	uint8_t	type;
	bool	is_inside;
}	t_hit;

typedef struct s_matrix_2x2
{
	float	m[2][2];
}	t_matrix_2x2;

typedef struct s_matrix_3x3
{
	float	m[3][3];
}	t_matrix_3x3;

typedef struct s_matrix_4x4
{
	float	m[4][4];
}	t_matrix_4x4;

typedef struct amb
{
	float		ka;
	t_color		la;
}	t_amb;

typedef struct s_cam
{
	float			aspect;
	float			fov;
	float			half_height;
	float			half_view;
	float			half_width;
	float			pixel_size;
	t_matrix_4x4	transform;
	t_point			cam_ori;
	t_vec			cam_dir;
	t_vec			forward;
	t_vec			left;
	t_vec			up;
}	t_camera;

typedef struct s_light
{
	float	bri;
	t_color	clr;
	t_point	pos;
}	t_light;

typedef struct s_material
{
	float	ambient;
	float	diffuse;
	float	shininess;
	float	specular;
	t_color	clr;
}	t_material;

typedef struct s_ray
{
	t_point	o;
	t_vec	d;
}	t_ray;

typedef struct s_sph
{
	float	sq_r;
	t_color	rgb;
	t_vec	c;
	t_vec	n;
	float	dif_fac;
	float	amb_fac;
	float	spec_fac;
}	t_sph;

typedef struct s_cyl
{
	float	dmt;
	float	rd1;
	float	rd2;
	t_color	rgb;
	t_vec	cnt;
	t_vec	nrm;
	float	hgt;
	float	dif_fac;
	float	amb_fac;
	float	spec_fac;
}	t_cyl;

typedef struct s_pln
{
	float	d;
	t_color	rgb;
	t_vec	n;
	t_vec	p;
}	t_pln;

typedef struct s_con
{
	float	fac;
	float	hgt;
	t_deg	ang;
	t_vec	cnt;
	t_vec	nrm;
	t_color	rgb;
}	t_con;

typedef struct obj
{
	struct obj	*next;
	uint8_t		type;
	union {
		t_con	con;
		t_cyl	cyl;
		t_pln	pln;
		t_sph	sph;
	};
}	t_obj;

typedef struct scn
{
	t_amb		amb;
	bool		is_amb;
	t_camera	cam;
	bool		is_cam;
	int			bpp;
	int			end;
	int			szl;
	t_light		light;
	bool		is_light;
	t_obj		*objs;
	void		*img;
	void		*mlx;
	void		*win;
}	t_scene;

#endif