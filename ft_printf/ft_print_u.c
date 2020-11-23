/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:26:38 by hekang            #+#    #+#             */
/*   Updated: 2020/11/23 10:27:24 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(t_dataopt *dopt, unsigned int n)
{
	int nwid;

	nwid = ft_nbrulen(n);
	n = ft_calc_print(&*dopt, n, nwid);
	inputpad('-', dopt->fminus);
	inputpad(' ', dopt->lspace);
	inputpad('-', dopt->mminus);
	inputpad('0', dopt->czero);
	if (!(dopt->ispoint && !dopt->preci))
		ft_putunbr(n);
	else if (dopt->dwidth)
		inputpad(' ', 1);
	else
		return (0);
	inputpad(' ', dopt->rspace);
	dopt->rvalue = dopt->lspace + dopt->czero \
		+ nwid + dopt->rspace;
	return (1);
}
