/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:11:19 by hekang            #+#    #+#             */
/*   Updated: 2021/02/15 15:53:00 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int     parse_plane(t_scene *scene, char *line)
{
    char        **s;
    t_vec       *origin;
    t_vec       *normal;
    t_vec       *color;
    char        **tmp;

    s = ft_split(line, ' ');
    if (s == 0 || !s[1] || !s[2] || !s[3] || s[4])
    {
        printf("ERROR : Init Plane\n");
        return (0);
    }
    tmp = ft_split(s[1], ',');
    origin = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
    tmp = ft_split(s[2], ',');
    normal = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
    tmp = ft_split(s[3], ',');
    color = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
    hitlst_add(scene->obj, (void *)init_plane(origin, normal, color), OBJ_PLANE);
    return (1);
}

int     parse_sphere(t_scene *scene, char *line)
{
    char        **s;
    t_vec       *origin;
    double      radius;
    t_vec       *color;
    char        **tmp;
    
    s = ft_split(line, ' ');
    if (s == 0 || !s[1] || !s[2] || !s[3] || s[4])
    {
        printf("ERROR : Init Sphere\n");
        return (0);
    }
    tmp = ft_split(s[1], ',');
    origin = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
    radius = ft_atod(s[2]);
    tmp = ft_split(s[3], ',');
    color = vec_create(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
    hitlst_add(scene->obj, (void *)init_sphere(origin, radius, color), OBJ_SPHERE);
    printf("radius: %f \n", radius);
    printf("color : %f %f %f\n", color->x, color->y, color->z);
    return (1);
}
