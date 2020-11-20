/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:03:34 by hekang            #+#    #+#             */
/*   Updated: 2020/11/20 11:13:53 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checkflag(char **str, t_dataopt *dataopt)
{
	while (isminus(**str) || iszero(**str))
	{
		if (isminus(**str))
			dataopt->isleft = 1;
		dataopt->iszero = 1;
		(*str)++;
	}
	if (dataopt->isleft && dataopt->iszero)
		dataopt->iszero = 0;
}

void	checkwidth(char **str, t_dataopt *dataopt)
{
	int	bstar;

	bstar = 0;
	while (isstar(**str))
	{
		dataopt->dwidth = va_arg(dataopt->valist, int);
		if (dataopt->dwidth < 0)
		{
			dataopt->isleft = 1;
			dataopt->iszero = 0;
			dataopt->dwidth = -dataopt->dwidth;
		}
		(*str)++;
		bstar = 1;
	}
	while (ft_isdigit(**str))
	{
		if (bstar == 1)
			dataopt->dwidth = 0;
		bstar = 0;
		dataopt->dwidth = dataopt->dwidth * 10 + **str - '0';
		(*str)++;
	}
}

void	checkprecision(char **str, t_dataopt *dataopt)
{
	int	bstar;

	bstar = 0;
	if (!ispoint(**str, &*dataopt))
		return ;
	(*str)++;
	while (isstar(**str))
	{
		dataopt->preci = va_arg(dataopt->valist, int);
		(*str)++;
		bstar = 1;
	}
	while (ft_isdigit(**str))
	{
		if (bstar == 1)
			dataopt->preci = 0;
		bstar = 0;
		dataopt->preci = dataopt->preci * 10 + **str - '0';
		(*str)++;
	}
}
