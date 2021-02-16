/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hittable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:18:41 by hekang            #+#    #+#             */
/*   Updated: 2021/02/16 11:54:41 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int                 cal_hittable_color(t_scene *scene, t_hit_record *rec)
{
    t_vec           *color;
    t_vec           *tmp;
    int             result;
    double          t;

    color = NULL;
    result = 0;
    if (hitlst_hit(scene->obj, rec))
    {
        // color = vec_add_apply(vec_create(1, 1, 1), info->rec->normal);
        // printf("22222222222\n");
        // printf("%f\n", rec->normal->z);
        // color = vec_create(0.6, 0, info->rec->normal->z / 3 );
        // color = vec_unit(rec->normal);
        // color = vec_create(0, 0, color->z - 0.3);
        tmp = vec_sub(rec->p, scene->light->origin);
        tmp = vec_unit(tmp);
        t = vec_dot(tmp, rec->normal);

        color = vec_create(rec->color->x, rec->color->y, rec->color->z);
        // tmp =vec_mul_const(color, t);

        // tmp = vec_add(tmp,vec_mul_const(light->color, light->ratio));

        tmp = vec_mul_const(scene->light->color, scene->light->ratio * t);
        tmp = vec_add(color, tmp);

        // color =vec_mul_const(color, t * light->ratio);
        color = vec_add(tmp, vec_mul_const(scene->ambient->color, scene->ambient->ratio));


        // color = vec_create(rec->color->x, rec->color->y, rec->color->z);
        // color = vec_mul_const(color, rec->t_max * light->ratio);
        // printf("t : %f \n", t);
        // printf("t_max : %f \n", rec->t_max);
        result = get_color(color);
        free(color);
    }
    // else
    // {
    //     tmp = vec_unit(rec->ray->dir);
    //     t = 0.5 * (tmp->y + 1.0);
    //     free(tmp);
    //     color = vec_mul_const_apply(vec_create(1, 1, 1), 1.0 - t);
    //     tmp = vec_mul_const_apply(vec_create(0.5, 0.7, 1), t);
    //     vec_add_apply(color, tmp);
    //     free(tmp);
    // }

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
    return (create_ray(cam->origin, tmp));
}

// void                draw_hittable(t_camera *cam, t_list *lst, t_light *light)
void                draw_hittable(t_scene *scene)
{
    int             x;
    int             y;
    double          u;
    double          v;
    t_hit_record    *rec;
    int n = 0;

    y = scene->img->height;
    while (n < scene->n_cam)
    {
        printf("11111\n");
        while ((--y) >= 0)
        {
            x = -1;
            while ((++x) < scene->img->width)
            {
                u = (double)x / (scene->img->width - 1);
                v = (double)y / (scene->img->height - 1);
                rec = hit_record_new();
                rec->ray = camera_get_ray(scene->cam->content, u, v);
                ((t_camera *)(scene->cam->content))->data->img[x][y] =
                    cal_hittable_color(scene, rec);
                free_hit_record(rec);
            }
        }
        printf("222\n");
        if (scene->cam->next)
        {
            printf("333\n");
            scene->cam = scene->cam->next;
            // ((t_camera *)(scene->cam->content))->data = scene->img;
        }
            printf("444\n");
            printf("content : %p\n",((t_camera *)(scene->cam->content)) );
            printf("x : %f\n", ((t_camera *)(scene->cam->content))->origin->x);
            printf("y : %f\n", ((t_camera *)(scene->cam->content))->origin->y);
            printf("z : %f\n", ((t_camera *)(scene->cam->content))->origin->z);
            // printf("00 : %d\n", ((t_camera *)(scene->cam->content))->data->img[0][0]);
            // printf("11 : %d\n", ((t_camera *)(scene->cam->content))->data->img[1][1]);
            
        y = scene->img->height;
        n++;
    }
}
