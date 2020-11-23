/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:18:23 by hekang            #+#    #+#             */
/*   Updated: 2020/11/23 15:59:07 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		remove_nagative(t_dataopt *dopt)
{
	if (dopt->czero < 0)
		dopt->czero = 0;
	if (dopt->lspace < 0)
		dopt->lspace = 0;
	if (dopt->rspace < 0)
		dopt->rspace = 0;
	if (dopt->fminus < 0)
		dopt->fminus = 0;
	if (dopt->mminus < 0)
		dopt->mminus = 0;
}

long long	ft_calc_l(t_dataopt *dopt, long long n, int nwid)
{
	dopt->fminus = (n < 0) ? 1 : 0;
	if (dopt->iszero && dopt->preci <= 0)
		dopt->czero = dopt->dwidth - nwid + dopt->fminus;
	else
		dopt->czero = dopt->preci - nwid + dopt->fminus;
	dopt->rspace = (dopt->dwidth > dopt->preci) ? dopt->dwidth -\
		(dopt->preci > nwid ? dopt->preci + dopt->fminus : nwid) : 0;
	dopt->lspace = 0;
	n = n < 0 ? -n : n;
	return (n);
}

long long	ft_calc_r(t_dataopt *dopt, long long n, int nwid)
{
	if (n < 0)
	{
		n = -n;
		dopt->mminus = 1;
		if (dopt->preci)
			dopt->preci++;
	}
	dopt->fminus = 0;
	if (dopt->iszero && dopt->preci)
		dopt->czero = dopt->dwidth - nwid;
	else
		dopt->czero = dopt->preci - nwid;
	if (dopt->czero < 0)
		dopt->czero = 0;
	dopt->lspace = (dopt->dwidth > dopt->czero + nwid) ?
		dopt->dwidth - nwid - dopt->czero : 0;
	dopt->rspace = 0;
	return (n);
}

long long	ft_calc_print(t_dataopt *dopt, long long n, int nwid)
{
	if (dopt->isleft)
		n = ft_calc_l(&*dopt, n, nwid);
	else
		n = ft_calc_r(&*dopt, n, nwid);
	remove_nagative(&*dopt);
	return (n);
}
