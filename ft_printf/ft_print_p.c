/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:24:58 by hekang            #+#    #+#             */
/*   Updated: 2020/11/23 10:33:03 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(t_dataopt *dopt, long long n)
{
	int	nwid;

	nwid = ft_nbrhexalen(n) + 2;
	n = ft_calc_print(&*dopt, n, nwid);
	inputpad('-', dopt->fminus);
	inputpad(' ', dopt->lspace);
	inputpad('-', dopt->mminus);
	inputpad('0', dopt->czero);
	if (!(dopt->ispoint && !dopt->preci))
		ft_putpointer(n);
	else //if (dopt->dwidth)
	{
		inputpad('0', 1);
		inputpad('x', 1);
		dopt->rvalue = 2;
		return (1);
	}
	inputpad(' ', dopt->rspace);
	dopt->rvalue = dopt->lspace + dopt->czero \
		+ nwid + dopt->rspace;
	return (1);
}
