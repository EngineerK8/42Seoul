/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:24:58 by hekang            #+#    #+#             */
/*   Updated: 2020/11/25 11:13:17 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(t_dataopt *dopt, long long n)
{
	int	nwid;

	nwid = ft_nbrhexalen(n) + 2;
	if (n == 0 && !dopt->preci && dopt->ispoint)
		nwid = 2;
	n = ft_calc_print(&*dopt, n, nwid);
	inputpad('-', dopt->fminus);
	inputpad(' ', dopt->lspace);
	inputpad('-', dopt->mminus);
	inputpad('0', dopt->czero);
	if (!dopt->ispoint || dopt->preci || n)
		ft_putpointer(n);
	else
		write(1, &"0x", 2);
	inputpad(' ', dopt->rspace);
	dopt->rvalue = dopt->lspace + dopt->czero \
		+ nwid + dopt->rspace;
	return (1);
}
