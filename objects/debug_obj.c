/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:12:27 by hjabbour          #+#    #+#             */
/*   Updated: 2023/02/05 19:41:17 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/declarations.h"
#include "../include/types.h"
#include "enums.h"
#include <math.h>
#include <stdint.h>

void	debug_camera(t_camera cam)
{
	print_vec(cam.cam_ori);
	print_vec(cam.cam_dir);
	printf("file_view: %f\n", cam.fov);
	print_matr4x4(cam.transform);
	printf("aspect %f\n", cam.aspect);
	printf("half_view %f\n", cam.half_view);
	printf("half_width %f\n", cam.half_width);
	printf("half_height %f\n", cam.half_height);
	printf("pixel_size %f\n", cam.pixel_size);
	printf("forward\n");
	print_vec(cam.forward);
	printf("up\n");
	print_vec(cam.up);
	printf("left\n");
	print_vec(cam.left);
}

void	debug_sphere(t_sph sp)
{
	printf("diameter: %.5f\n", sp.sq_r);
	print_clr(sp.rgb);
	print_vec(sp.c);
	print_vec(sp.n);
	printf("dif_fac: %.5f\n", sp.dif_fac);
	printf("amb_fac: %.5f\n", sp.amb_fac);
	printf("spec_fac: %.5f\n", sp.spec_fac);
}

void	debug_ray(t_ray ray)
{
	print_vec(ray.o);
	print_vec(ray.d);
}
