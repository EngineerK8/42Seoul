/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:56:36 by hekang            #+#    #+#             */
/*   Updated: 2020/11/22 23:40:11 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		initdata(t_dataopt *dataopt)
{
	dataopt->dwidth = 0;
	dataopt->isleft = 0;
	dataopt->iszero = 0;
	dataopt->preci = 0;
	dataopt->ispoint = 0;
	dataopt->czero = 0;
	dataopt->lspace = 0;
	dataopt->rspace = 0;
	dataopt->fminus = 0;
	dataopt->mminus = 0;
	dataopt->rvalue = 1;
	return (1);
}

void	ft_printarg(char c, t_dataopt *dataopt)
{
	if (c == 'd' || c == 'i')
		ft_print_d(&*dataopt, va_arg(dataopt->valist, int));
	if (c == 'c')
		ft_print_c(&*dataopt, va_arg(dataopt->valist, int));
	if (c == 's')
		ft_print_s(&*dataopt, va_arg(dataopt->valist, char *));
	if (c == 'X')
		ft_print_x(&*dataopt, va_arg(dataopt->valist, int), 1);
	if (c == 'x')
		ft_print_x(&*dataopt, va_arg(dataopt->valist, int), 2);
	if (c == 'p')
		ft_print_p(&*dataopt, (long long)va_arg(dataopt->valist, void *));
	if (c == 'u')
		ft_print_u(&*dataopt, (unsigned int)va_arg(dataopt->valist, int));
	if (c == '%')
		ft_print_percent(&*dataopt);
}

int		ft_printf(const char *types, ...)
{
	char		*str;
	t_dataopt	dataopt;
	int			rvalue;

	rvalue = 0;
	va_start(dataopt.valist, types);
	str = (char *)types;
	while (*str)
	{
		initdata(&dataopt);
		if (*(str + 1) && *str == '%' && isrightcont(str, &dataopt))
		{
			str++;
			checkflag(&str, &dataopt);
			checkwidth(&str, &dataopt);
			checkprecision(&str, &dataopt);
			ft_printarg(*str, &dataopt);
		}
		else
			write(1, str, 1);
		str++;
		rvalue += dataopt.rvalue;
	}
	va_end(dataopt.valist);
	return (rvalue);
}
