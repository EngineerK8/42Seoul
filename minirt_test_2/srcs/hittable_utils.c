/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:14:55 by hekang            #+#    #+#             */
/*   Updated: 2021/02/05 16:19:19 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hittable          *hittable_create(void *obj, int obj_type)
{
    t_hittable      *result;

    result = (t_hittable *)malloc(sizeof(t_hittable));
    result->obj = obj;
    result->obj_type = obj_type;
    if (obj_type == OBJ_SPHERE)
        result->hit = &sphere_hit;
    if (obj_type == OBJ_PLANE)
        result->hit = &plane_hit;
    return (result);
}