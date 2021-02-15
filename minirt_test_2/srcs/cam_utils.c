/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:26:06 by hekang            #+#    #+#             */
/*   Updated: 2021/02/15 09:44:55 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			set_camera_llc(t_camera *cam, t_vec *lookat)
{
	t_vec		*tmp;

	vec_div_const_apply(cam->horizontal, 2.0);
	vec_div_const_apply(cam->vertical, 2.0);
	tmp = vec_add(cam->horizontal, cam->vertical);
	vec_add_apply(tmp, lookat);
	cam->lower_left_corner = vec_sub(cam->origin, tmp);
	free(tmp);
	vec_mul_const_apply(cam->horizontal, 2.0);
	vec_mul_const_apply(cam->vertical, 2.0);
}

t_camera        *init_cam(t_vec *lookfrom, t_vec *lookat, double aspect_ratio, double hfov)
{
    t_camera    *result;
    double      view_h;
    double      view_w;
    t_vec       *vup;

	lookat = vec_unit(vec_mul_const_apply(lookat, -1.0));
    vup = vec_create(0, 1, 0);
	if (vec_is_parallel(vup, lookat))
	{
		free(vup);
		vup = vec_create(1, 0, 0);
	}
    result = (t_camera *)malloc(sizeof(t_camera));
    view_w = 2 * tan(hfov / 2.0);
    view_h = view_w / aspect_ratio;
    result->horizontal = vec_unit(vec_cross(vup, lookat));
	result->vertical = vec_mul_const_apply(
							vec_cross(lookat, result->horizontal), view_h);
	vec_mul_const_apply(result->horizontal, view_w);
	result->origin = lookfrom;
    set_camera_llc(result, lookat);
    // result->lower_left_corner = vec_sub(result->origin, vec_create(view_w / 2, view_h / 2, view_w / (2 * tan(vfov / 2.0 * PI /180 ))));

	// set_camera_llc(result, lookat);
	free(lookat);
	return (result);
}

t_camera        *create_cam(double aspect_ratio)
{
    t_camera    *result;
    double      viewport_height;
    double      viewport_width;
    double      focal_length;

    result = (t_camera *)malloc(sizeof(t_camera));
    result->aspect_ratio = aspect_ratio;
    focal_length = 1.0;
    viewport_height = 30.0;
    viewport_width = viewport_height * aspect_ratio;
    result->origin = vec_create(0, 0, 0);
    result->horizontal = vec_create(viewport_width, 0, 0);
    result->vertical = vec_create(0, viewport_height, 0);
    result->lower_left_corner = vec_sub(result->origin, vec_create(viewport_width / 2, viewport_height / 2, focal_length));
    //result->lower_left_corner = vec_sub(result->origin, vec_create((result->horizontal->x) / 2, result->vertical->y / 2, focal_length));
    return (result);
}