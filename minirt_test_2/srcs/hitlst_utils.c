/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitlst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:10:34 by hekang            #+#    #+#             */
/*   Updated: 2021/01/19 17:14:51 by hekang           ###   ########.fr       */
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