/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:33:43 by hekang            #+#    #+#             */
/*   Updated: 2021/02/05 22:40:18 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light     *init_light(t_vec *ori, double ratio, t_vec *color, t_ambient  *A)
{
    t_light *result;

    result = (t_light *)malloc(sizeof(t_light));
    result->origin = ori;
    result->ratio = ratio;
    result->color = color;
    result->a_color = A->color;
    result->a_ratio = A->ratio;
    return (result);
}