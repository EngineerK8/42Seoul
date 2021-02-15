/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:08:25 by hekang            #+#    #+#             */
/*   Updated: 2021/02/15 09:58:44 by hekang           ###   ########.fr       */
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
    t_plane     *pl;
    t_light     *l;
    t_ambient   *A;


    image_width = 1080;
    double image_height = 720;
    aspect_ratio = image_width / image_height;
    // cam = init_cam(vec_create(-2, 2, 5), vec_create(1, -1, -1), aspect_ratio, 130 * PI / 180.0);
    cam = init_cam(vec_create(-50, 0, 20), vec_create(1, 0, 0), aspect_ratio, 70 * PI / 180.0);
    // data = create_img_data(image_width, (int)(image_width / aspect_ratio));
    data = create_img_data(image_width, image_height);
    cam->data = data;
    A = init_ambient(0.2, vec_create(1, 1, 1));
    l = init_light(vec_create(-40, 20, 20), 0.7, vec_create(1, 1, 1), A);
    hitlst = hitlst_new();
    s = init_sphere(vec_create( -10, 10, 20), 4, vec_create(0, 1, 0), vec_create(1, 1, 1));
    hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
    s = init_sphere(vec_create( -30, -40, -20), 4, vec_create(0, 1, 0), vec_create(1, 1, 1));
    hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
    s = init_sphere(vec_create( 0, 0, 30), 4, vec_create(1, 0, 0), vec_create(1, 1, 1));
    hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
    s = init_sphere(vec_create( 10, 0, 10), 4, vec_create(0, 0, 1), vec_create(1, 1, 1));
    hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
    pl = init_plane(vec_create(0, -4, 0), vec_create(0, -1, 0), vec_create(0.2, 0.2, 0.2));
    hitlst_add(hitlst, (void *)pl, OBJ_PLANE);
    draw_hittable(cam, hitlst, l);

    mlx_show(data, "miniRT");
}
