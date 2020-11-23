/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:22:31 by hekang            #+#    #+#             */
/*   Updated: 2020/11/23 09:30:58 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(t_dataopt *dopt, int n)
{
	int wid;

	wid = 1;
	if (dopt->isleft)
	{
		ft_putchar(n);
		inputpad(' ', dopt->dwidth - wid);
	}
	else if (dopt->dwidth > wid)
	{
		inputpad(' ', dopt->dwidth - wid);
		ft_putchar(n);
	}
	else
		ft_putchar(n);
	dopt->rvalue = dopt->dwidth;
	return (1);
}

int	ft_print_s(t_dataopt *dopt, char *s)
{
	int wid;

	if (!s)
		s = "(null)";
	wid = ft_strlen(s);
	if (dopt->preci > 0)
		wid = (dopt->preci > wid) ? wid : dopt->preci;
	if (dopt->ispoint && !dopt->preci)
	{
		inputpad(' ', dopt->dwidth);
		dopt->rvalue = dopt->dwidth;
		return (1);
	}
	if (dopt->isleft)
	{
		ft_putnstr(s, wid);
		inputpad(' ', dopt->dwidth - wid);
	}
	else
	{
		inputpad(' ', dopt->dwidth - wid);
		ft_putnstr(s, wid);
	}
	dopt->rvalue = (dopt->dwidth > wid) ? dopt->dwidth : wid;
	return (1);
}
