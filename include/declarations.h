/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declarations.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:12:53 by stamim            #+#    #+#             */
/*   Updated: 2023/02/05 15:22:55 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECLARATIONS_H
# define DECLARATIONS_H

# include "types.h"
# include <stdbool.h>
# include <stdint.h>

bool			is_equal_matri2x2(t_matrix_2x2 mat1, t_matrix_2x2 mat2);
bool			is_equal_matri3x3(t_matrix_3x3 mat1, t_matrix_3x3 mat2);
bool			is_equal_matri4x4(t_matrix_4x4 mat1, t_matrix_4x4 mat2);
bool			is_equal_vec(t_vec vec1, t_vec vec2);
bool			is_equal(float val1, float val2);
char			*ft_itoa(int n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
float			cofactor_matr3x3(t_matrix_3x3 mat, int row, int col);
float			determ_matr2x2(t_matrix_2x2 mat);
float			determ_matr3x3(t_matrix_3x3 mat);
float			determ_matr4x4(t_matrix_4x4 mat);
float			rt_get_val(char *num, bool *err);
float			tup_length(t_vec *vec);
float			vec_dot_product_vec(t_vec vec1, t_vec vec2);
float			vec_dot_product(t_vec vec);
float			vec_length(t_vec vec);
int				event_on_keydown(t_keycode key, void *arg);
int				ft_isdigit(char chr);
int				ft_strcmp(const char *str, const char *to_cmp);
int				generate_color(t_color clr);
int				rt_destroy(t_scene *scn);
int				rt_open(int argc, const char *arg);
size_t			ft_strlen(const char *str);
t_color			clamp(t_color clr);
t_color			clr_add_clr(t_color vec, t_color val);
t_color			clr_add_value(t_color vec, float val);
t_color			clr_multi_clr(t_color vec, t_color val);
t_color			clr_multi_value(t_color vec, float val);
t_color			light_coloring(const t_ray ray, const t_hit hit,
					const t_scene *scn, const t_obj *obj);
t_color			objects_coloring(t_ray ray, const t_scene *scn);
t_color			rt_get_color(char *color, bool *err);
t_deg			rad_to_deg(t_rad rad);
void			rt_cyl_closest_hit(t_cyl cyl, t_ray ray, t_hit *hit);
void			rt_pln_closest_hit(t_pln pln, t_ray ray, t_hit *hit);
void			rt_sph_closest_hit(t_sph sph, t_ray ray, t_hit *hit);
t_matrix_2x2	sub_matr3x3(t_matrix_3x3 mat, int row, int col);
t_matrix_3x3	sub_matr4x4(t_matrix_4x4 mat, int row, int col);
t_matrix_4x4	invers_matr4x4(t_matrix_4x4 mat);
t_matrix_4x4	matr4x4_identity(void);
t_matrix_4x4	matr4x4_multi_matr4x4(t_matrix_4x4 mat1, t_matrix_4x4 mat2);
t_matrix_4x4	matr4x4_rotation_x(t_rad rad);
t_matrix_4x4	matr4x4_rotation_y(const t_rad rad);
t_matrix_4x4	matr4x4_rotation_z(const t_rad rad);
t_matrix_4x4	matr4x4_rotation(float x, float y, float z);
t_matrix_4x4	matr4x4_scaling(float x, float y, float z);
t_matrix_4x4	matr4x4_shearing(float x[2], float y[2], float z[2]);
t_matrix_4x4	matr4x4_translation(float x, float y, float z);
t_matrix_4x4	matr4x4_transpos(t_matrix_4x4 mat);
t_matrix_4x4	view_transform(t_vec forward, t_point from, t_vec up);
t_point			matr4x4_multi_point(t_matrix_4x4 mat, t_point pnt);
t_point			point(const float x, const float y, const float z);
t_point			ray_position(t_ray ray, float t);
t_rad			deg_to_rad(t_deg deg);
t_ray			ray_for_pixel(t_camera cam, int y, int x);
t_tuple			matr4x4_multi_tuple(t_matrix_4x4 mat, t_tuple tup);
t_tuple			tup_div_value(t_tuple vec, float val);
t_tuple			tup_div_vec(t_tuple vec, t_tuple val);
t_tuple			tup_multi_value(t_tuple vec, float val);
t_tuple			tup_multi_vec(t_tuple vec, t_tuple val);
t_tuple			tup_normalize(t_tuple vec);
t_tuple			tuple_add_value(t_tuple vec, float val);
t_tuple			tuple_add_vec(t_tuple vec, t_tuple val);
t_tuple			tuple_sub_value(t_tuple vec, float val);
t_tuple			tuple_sub_vec(t_tuple vec, t_tuple val);
t_vec			matr4x4_multi_vec(t_matrix_4x4 mat, t_vec vec);
t_vec			normal_at_sphere(t_point obj_ori, t_point pnt);
t_vec			reflect(t_vec in, t_vec normal);
t_vec			rt_get_coordinates(char *name, bool *err, int type);
t_vec			rt_pln_normal_at(t_pln pln, t_vec pnt);
t_vec			rt_sph_normal_at(t_sph sph, t_vec pnt);
t_vec			up_vec(t_vec forw);
t_vec			vec_add_value(t_vec vec, float val);
t_vec			vec_add_vec(t_vec vec, t_vec val);
t_vec			vec_cross_product(t_vec first, t_vec second);
t_vec			vec_div_value(t_vec vec, float val);
t_vec			vec_div_vec(t_vec vec, t_vec val);
t_vec			vec_multi_value(t_vec vec, float val);
t_vec			rt_sph_get_normal_at(t_sph sph, t_vec pnt);
t_vec			rt_pln_get_normal_at(t_pln pln, t_vec dir);
t_vec			rt_cyl_normal_at(t_cyl cyl, t_hit hit, t_ray ray);
t_vec			rt_con_normal_at(t_con con, t_hit hit, t_ray ray);
t_qud			rt_sol_qua_eq(float cf1, float cf2, float cf3);
t_vec			vec_multi_vec(t_vec vec, t_vec val);
t_vec			vec_normalize(t_vec vec);
t_vec			vec_sub_value(t_vec vec, float val);
t_vec			vec_sub_vec(t_vec vec, t_vec val);
t_vec			vector(const float x, const float y, const float z);
void			debug_camera(t_camera cam);
void			debug_ray(t_ray ray);
void			debug_sphere(t_sph sp);
void			generate_camera(t_scene *scn);
void			print_clr(t_color clr);
void			print_matr2x2(t_matrix_2x2 mat);
void			print_matr3x3(t_matrix_3x3 mat);
void			print_matr4x4(t_matrix_4x4 mat);
void			print_pnt(t_point pnt);
void			print_vec(t_vec vec);
void			rt_destroy_objs(t_scene *scn);
void			rt_exit(const char *str);
void			rt_con_closest_hit(t_con con, t_ray ray, t_hit *hit);
void			rt_parse_con(t_scene *scn, char **args);
void			rt_parse_amb(t_scene *scn, char **args);
void			rt_parse_cam(t_scene *scn, char **args);
void			rt_parse_light(t_scene *scn, char **args);
void			rt_parse_obj(t_scene *scn, char **args);
void			rt_parse(t_scene *scn, int file, char *line);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
t_hit			closest_object(const t_obj **obj, t_ray ray,
					const t_obj *cur_obj, const t_obj *jump);
t_vec			get_normal_at(const t_obj *obj, t_ray ray, t_hit hit,
					const t_point pnt);
t_color			clr_div_value(t_color vec, float val);
t_color			clr_div_clr(t_color vec, t_color val);
bool			check_rgb(t_color clr);
bool			check_ratio(float ratio);
bool			accepted_values(const t_scene *scn);

#endif