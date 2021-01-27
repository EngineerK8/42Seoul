/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:26:06 by hekang            #+#    #+#             */
/*   Updated: 2021/01/25 15:32:56 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera        *create_cam(double aspect_ratio)
{
    t_camera    *result;
    double      viewport_height;
    double      viewport_width;
    double      focal_length;

    result = (t_camera *)malloc(sizeof(t_camera));
    result->aspect_ratio = aspect_ratio;
    focal_length = 1.0;
    viewport_height = 2.0;
    viewport_width = viewport_height * aspect_ratio;
    result->origin = vec_create(0, 0, 0);
    result->horizontal = vec_create(viewport_width, 0, 0);
    result->vertical = vec_create(0, viewport_height, 0);
    result->lower_left_corner = vec_sub(result->origin, vec_create(viewport_width / 2, viewport_height / 2, focal_length));
    //result->lower_left_corner = vec_sub(result->origin, vec_create((result->horizontal->x) / 2, result->vertical->y / 2, focal_length));
    return (result);
}