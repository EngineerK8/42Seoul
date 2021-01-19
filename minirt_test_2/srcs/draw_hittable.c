/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hittable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:18:41 by hekang            #+#    #+#             */
/*   Updated: 2021/01/19 17:21:52 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void                draw_hittable(t_camera *cam, t_list *lst)
{
    int             x;
    int             y;
    double          u;
    double          v;
    t_hitlst_info   *lst_info;

    y = cam->data->height;
    while ((--y) >= 0)
    {
        x = -1;
        while ((++x) < cam->data->width)
        {
            u = (double)(x / (cam->data->width - 1));
            v = (double)(y / (cam->data->height - 1));
            lst_info = hitlst_info_new(camera_get_ray(cam, u, v));
            cam->data->img[x][y] = cal_hittable_color(lst, lst_info);
            free_hitlst_info(lst_info, FALSE);
        }
    }
}
