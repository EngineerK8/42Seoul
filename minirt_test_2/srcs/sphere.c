/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:15:49 by hekang            #+#    #+#             */
/*   Updated: 2021/01/27 17:38:41 by hekang           ###   ########.fr       */
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
    result->albedo = albedo;
    return (result);
}

int			check_sphere_hitrange(void *s, t_ray *r,
									t_hitlst_info *info, t_hit_record *rec)
{
	int		is_big_t;
	double	t;

	is_big_t = -1;
	while ((++is_big_t) < 2)
	{
		t = (-info->b / 2 + info->root_d * (is_big_t ? (1) : (-1))) / info->a;
		if (info->t_min < t && t < info->t_max)
		{
			if (rec->p)
				reset_hit_record(rec);
			rec->t = t;
			rec->p = ray_at(r, t);
			rec->normal = vec_sub(rec->p, ((t_sphere *)s)->center);
			vec_div_const_apply(rec->normal, ((t_sphere *)s)->radius);
			hit_set_normal(rec, r);
			// rec->mat = info->mat;
			return (TRUE);
		}
	}
	return (FALSE);
}

int         sphere_hit(void *s, t_ray *r, t_hitlst_info *info, t_hit_record *rec)
{
    double      discriminant;
    double      a;
    double      b;
    double      c;
    t_vec       *oc;

    oc = vec_sub(r->orig, ((t_sphere *)s)->center);
    a = vec_dot(r->dir, r->dir);
    b = 2.0 * vec_dot(r->dir, oc);
    c = vec_dot(oc, oc) - pow(((t_sphere *)s)->radius, 2);
    discriminant = pow(b / 2, 2) - a * c;

    if (discriminant <= 0)
        return (FALSE);
    info->a = a;
    info->b = b;
    info->root_d = sqrt(discriminant);
    return (check_sphere_hitrange(s, r, info, rec));


    // if (discriminant < 0)
    //     return (-1.0);
    // else
    // {
    //     c = (-b - sqrt(discriminant)) / (2.0 * a);
    //     if (c < 0)
    //         c = (-b + sqrt(discriminant)) / (2.0 * a);
    //     return (c);
    // }
}