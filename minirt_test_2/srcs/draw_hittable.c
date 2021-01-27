/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hittable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:18:41 by hekang            #+#    #+#             */
/*   Updated: 2021/01/27 18:33:17 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int                 cal_hittable_color(t_list *lst, t_hitlst_info *info)
{
    t_vec           *color;
    t_vec           *tmp;
    int             result;
    double          t;

    if (hitlst_hit(lst, info))
    {
        t = 1;
        // color = vec_add_apply(vec_create(1, 1, 1), info->rec->normal);
        printf("%f\n", info->rec->normal->z);
        color = vec_create(0.6, 0, info->rec->normal->z / 3 );

        // color = vec_unit(vec_sub(info->ray, vec_create(0, 0, -1))); //center_point
        // color = vec_create(0, 0, color->z);
        // color = info->rec->normal;
        // color = vec_unit(vec_sub( vec_create(0.15, 0.15, -0.8), tmp)); //center_point
        // vec_mul_const_apply(color, 0.5);
    }
    else
    {
        tmp = vec_unit(info->ray->dir);
        t = 0.5 * (tmp->y + 1.0);
        free(tmp);
        color = vec_mul_const_apply(vec_create(1, 1, 1), 1.0 - t);
        tmp = vec_mul_const_apply(vec_create(0.5, 0.7, 1), t);
        vec_add_apply(color, tmp);
        free(tmp);
    }

    result = get_color(color);
    free(color);
    return (result);
}

t_ray               *camera_get_ray(t_camera *cam, double u, double v)
{
    t_vec           *tmp;
    t_vec           *tmp2;

    tmp2 = vec_mul_const(cam->horizontal, u);
    tmp = vec_add(cam->lower_left_corner, tmp2);
    free(tmp2);  
    tmp2 = vec_mul_const(cam->vertical, v);
    vec_add_apply(tmp, tmp2);
    free(tmp2);
    vec_sub_apply(tmp, cam->origin);
    // printf("ray->x : %f\n", tmp->x);
    // printf("u : %f\n", u);
    // printf("v : %f\n", v);
    return (create_ray(cam->origin, tmp));
}

void                draw_hittable(t_camera *cam, t_list *lst)
{
    int             x;
    int             y;
    double          u;
    double          v;
    t_hitlst_info   *lst_info;

    y = cam->data->height;
    // printf("y: %d \n", y);
    // printf("cam->data->width: %d \n", cam->data->width);
    // printf("cam->data->height: %d \n", cam->data->height);
    while ((--y) >= 0)
    {
        x = -1;
        while ((++x) < cam->data->width)
        {
            u = (double)x / (cam->data->width - 1);
            v = (double)y / (cam->data->height - 1);
            // printf("u: %f / v: %f\n", u, v);
            lst_info = hitlst_info_new(camera_get_ray(cam, u, v));
            cam->data->img[x][y] = cal_hittable_color(lst, lst_info);
            free_hitlst_info(lst_info, FALSE);
        }
    }
}
