/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:21:37 by hekang            #+#    #+#             */
/*   Updated: 2020/11/23 10:25:55 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_print_d(t_dataopt *dopt, int n)
{
	int nwid;

	nwid = ft_nbrlen(n);
	n = ft_calc_print(&*dopt, n, nwid);
	inputpad('-', dopt->fminus);
	inputpad(' ', dopt->lspace);
	inputpad('-', dopt->mminus);
	inputpad('0', dopt->czero);
	if (!(dopt->ispoint && !dopt->preci))
		ft_putnbr(n);
	else if (dopt->dwidth)
		inputpad(' ', 1);
	else
		return (1);
	inputpad(' ', dopt->rspace);
	dopt->rvalue = dopt->lspace + dopt->czero \
		+ nwid + dopt->rspace;
	return (1);
}
