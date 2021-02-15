/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:35:12 by hekang            #+#    #+#             */
/*   Updated: 2021/02/05 16:44:39 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane         *init_plane(t_vec *p, t_vec *normal, t_vec *albedo)
{
    t_plane     *result;

    result = (t_plane *)malloc(sizeof(t_plane));
    result->p = p;
    result->normal = normal;
    result->albedo = albedo;
    return (result);
}

int             plane_hit(void *obj, t_ray *r, t_hit_record *rec)
{
    double      denominator; //분모
    t_plane     *pl;
    t_vec       *oc;
    double      root;

    pl = ((t_plane *)obj);
    denominator = vec_dot(pl->normal, r->dir);
    if (fabs(denominator) < 0.000001)
        return (FALSE);
    oc = vec_sub(pl->p, r->orig);
    root = vec_dot(oc, pl->normal) / denominator;
    if (root < rec->t_min || root > rec->t_max)
        return (FALSE);
    rec->t = root;
    rec->p = ray_at(r, root);
    rec->normal = vec_unit(pl->normal);
    rec->color = pl->albedo;
    return (TRUE);
}