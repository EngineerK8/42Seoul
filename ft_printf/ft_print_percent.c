/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:27:09 by hekang            #+#    #+#             */
/*   Updated: 2020/11/23 10:00:02 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(t_dataopt *dopt)
{
	if (dopt->isleft)
	{
		ft_putchar('%');
		inputpad(' ', dopt->dwidth - 1);
	}
	else if (dopt->iszero)
	{
		inputpad('0', dopt->dwidth - 1);
		ft_putchar('%');
	}
	else
	{
		inputpad(' ', dopt->dwidth - 1);
		ft_putchar('%');
	}
	dopt->rvalue = dopt->dwidth;
	if (dopt->rvalue == 0)
		dopt->rvalue = 1;
	return (1);
}
