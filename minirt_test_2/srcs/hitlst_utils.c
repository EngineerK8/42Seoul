/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitlst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:10:34 by hekang            #+#    #+#             */
/*   Updated: 2021/01/27 18:04:43 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list      *hitlst_new(void)
{
    t_list  *result;

    result = (t_list *)malloc(sizeof(t_list));
    result->content = NULL;
    result->next = NULL;
    return (result);
}

void        hitlst_add(t_list *lst, void *obj, int obj_type)
{
    if (lst->content)
    {
        while (lst->next)
            lst = lst->next;
        lst->next = hitlst_new();
        lst = lst->next;
    }
    lst->content = hittable_create(obj, obj_type);
}

int         hitlst_hit(t_list *lst, t_hitlst_info *info)
{
    int         hit_anything;
    t_hittable  *hittable;

    hit_anything = 0;
    while (lst && lst->content)
    {
        hittable = (t_hittable *)(lst->content);
        if ((*(hittable->hit))(hittable->obj, info->ray, info, info->rec))
        {
            hit_anything = 1;
            info->t_max = info->rec->t;
            return (1);
        }
        lst = lst->next;
    }
    // printf("000\n");
    // printf("hit_anything :%d \n", hit_anything);
    
    return (0);
}

