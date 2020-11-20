/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:23:56 by hekang            #+#    #+#             */
/*   Updated: 2020/11/20 16:45:25 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(t_dataopt *dopt, unsigned int n, int type)
{
	int nwid;

	nwid = ft_nbrhexalen(n);
	n = ft_calc_print(&*dopt, n, nwid);
	inputpad('-', dopt->fminus);
	inputpad(' ', dopt->lspace);
	inputpad('-', dopt->mminus);
	inputpad('0', dopt->czero);
	if (!(dopt->ispoint && !dopt->preci))
		ft_puthexa(n, type, n);
	else if (dopt->dwidth)
		inputpad(' ', 1);
	inputpad(' ', dopt->rspace);
	dopt->rvalue = dopt->fminus + dopt->lspace + dopt->mminus + dopt->czero +
		dopt->rspace + nwid;
	return (1);
}
