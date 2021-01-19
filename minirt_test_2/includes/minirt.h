/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:00:32 by hekang            #+#    #+#             */
/*   Updated: 2021/01/17 11:18:53 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define PI 3.14159265358917932385
# define OBJ_SPHERE 1
# define ANTI_SAMPLES 50
# define REFLECT_DEPTH 5
# define X_KEY_PRESS 2
# define X_KEY_RELEASE 3

# define TRUE 1
# define FALSE 2
# define HIT_T_MIN 0.001

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "minirt_struct.h"

t_img_data      *create_img_data(int width, int height);
void            mlx_show(t_img_data *data, char *title);
void                *free_img_data(t_img_data *data);
t_camera        *camera_locate(double aspect_ratio);
void                free_camera(t_camera *cam);
t_list          *hitlst_new(void);
t_sphere        *init_sphere(t_vec *center, double radius, t_vec *color, t_vec *albedo);
//t_sphere        *init_sphere(t_vec *center, double diameter, t_vec *color);
void            hitlst_add(t_list *lst, void *obj, int obj_type);
void            free_hitlst(t_list *lst);
void        mlx_show(t_img_data *data, char *title);
t_hittable      *hittable_create(void *obj, int obj_type);
void			free_hittable(t_hittable *h);
int         sphere_hit(void *s, t_ray *r, t_hitlst_info *info, t_hit_record *rec);
void        free_sphere(t_sphere *s);

t_vec       *vec_create(double x, double y, double z);
t_vec	*vec_add_apply(t_vec *a, t_vec *b);
t_vec	*vec_sub_apply(t_vec *a, t_vec *b);
t_vec	*vec_mul_const_apply(t_vec *a, double c);
t_vec	*vec_div_const_apply(t_vec *a, double c);
t_vec		*vec_add(t_vec *a, t_vec *b);
t_vec		*vec_sub(t_vec *a, t_vec *b);
t_vec		*vec_mul_const(t_vec *a, double c);
t_vec		*vec_div_const(t_vec *a, double c);
t_vec		*vec_reflect(t_vec *v, t_vec *n);
double      vec_dot(t_vec *u, t_vec *v);
double      vec_len_sqrt(t_vec *u);
t_vec       *vec_cross(t_vec *u, t_vec *v);
t_vec       *vec_unit(t_vec *u);
t_hit_record	*hit_record_new(void);
void			reset_hit_record(t_hit_record *rec);
void			free_hit_record(t_hit_record *rec);
void			hit_set_normal(t_hit_record *record, t_ray *r);
void				draw_hittable(t_camera *cam, t_list *lst);
void	color_map(void *mlx, void *win,int w,int h);

t_vec       *ray_at(t_ray *ray, double t);
t_ray       *create_ray(t_vec *origin, t_vec *direction);
void       free_ray(t_ray *ray);
double	clamp(double x, double min, double max);
int             get_color(t_vec *color);
t_vec         *ray_color(t_ray *r);
t_camera        *create_cam(double aspect_ratio);
void        draw_sky(t_img_data *data, t_camera *cam);

#endif