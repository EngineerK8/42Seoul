/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:08:25 by hekang            #+#    #+#             */
/*   Updated: 2021/01/27 20:21:14 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main()
{
    t_img_data  *data;
    t_camera    *cam;
    double      aspect_ratio;
    int         image_width;
    t_sphere    *s;
    t_list      *hitlst;

    image_width = 400;
    aspect_ratio = 16.0 / 9.0;
    cam = create_cam(aspect_ratio);
    data = create_img_data(image_width, (int)(image_width / aspect_ratio));
    cam->data = data;
    s = init_sphere(vec_create(0, 0, -1), 0.5, vec_create(1, 0, 1), vec_create(0, 0, 0));
    hitlst = hitlst_new();
    hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
    s = init_sphere(vec_create(0, 0.5, -1.5), 1, vec_create(0, 1, 1), vec_create(0, 0, 0));
    hitlst_add(hitlst, (void *)s, OBJ_SPHERE);

    draw_hittable(cam, hitlst);
    
    // draw_sky(data, cam);
    //draw_circle(data, cam);

    mlx_show(data, "miniRT");
}
