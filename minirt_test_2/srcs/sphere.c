/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:15:49 by hekang            #+#    #+#             */
/*   Updated: 2021/01/17 11:18:25 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere        *init_sphere(t_vec *center, double radius, t_vec *color, t_vec *albedo)
{
    t_sphere    *result;

    result = (t_sphere *)malloc(sizeof(t_sphere));
    result->center = center;
    result->radius = radius;
    result->color = color;
    result->color = albedo;
    return (result);
}