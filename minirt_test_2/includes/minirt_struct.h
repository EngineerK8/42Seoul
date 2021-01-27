/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:04:48 by hekang            #+#    #+#             */
/*   Updated: 2021/01/25 15:46:21 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

typedef struct      s_img_data
{
    int             **img;
    int             width;
    int             height;
}                   t_img_data;

typedef struct      s_vec
{
    double          x;
    double          y;
    double          z;
}                   t_vec;

typedef struct      s_camera
{
    t_img_data      *data;
    double          aspect_ratio;
    t_vec           *origin;
    t_vec           *lower_left_corner;
    t_vec           *horizontal;
    t_vec           *vertical;
}                   t_camera;

typedef struct      s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;

typedef struct      s_sphere
{
    t_vec           *center;
    double          radius;
    t_vec           *color;
    t_vec           *albedo;
}                   t_sphere;

typedef struct      s_ray
{
    t_vec           *orig;
    t_vec           *dir;
}                   t_ray;

typedef struct          s_hit_record
{
    t_vec               *p;
    t_vec               *normal;
    double              t;
    int                 is_front_face;
}                       t_hit_record;

typedef struct          s_hitlst_info
{
    t_ray               *ray;
    double              t_min;
    double              t_max;
    double              a;
    double              b;
    double              root_d;
    t_hit_record        *rec;
}                       t_hitlst_info;

typedef struct      s_hittable
{
    void            *obj;
    int             obj_type;
    int             (*hit)(void *s, t_ray *r, t_hitlst_info *info, t_hit_record *);
}                   t_hittable;

typedef struct			s_mlx_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_mlx_data;

typedef struct      s_vars
{
    void            *mlx;
    void            *win;
}                   t_vars;

#endif