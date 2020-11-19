/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:56:36 by hekang            #+#    #+#             */
/*   Updated: 2020/11/19 20:58:26 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"

int	initdata(t_dataopt *dataopt)
{
	dataopt->dwidth = 0;
	dataopt->isleft = 0;
	dataopt->iszero = 0;
	dataopt->preci = 0;
	dataopt->ispoint = 0;	
	return (1);
}

int	isparam(char c)
{
	if (c == 'd' || c == 'i' || c == 'c' || c == 's' || c == 'X' ||
			c == 'x' || c == 'p' || c == 'u' || c == '%')
		return (1);
	return (0);
}

int	isminus(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

int	iszero(char s)
{
	if (s == '0')
		return (1);
	return (0);
}

int	ispoint(char c, t_dataopt *dataopt)
{
	if (c == '.')
	{
		dataopt->ispoint = 1;
		return (1);
	}
	return (0);
}

int	isstar(char c)
{
	if (c == '*')
		return (1);
	return (0);
}

void	checkflag(char **str,t_dataopt *dataopt) // -, 0, . *
{
	int j;

	j = 0;
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


int	isrightcont(char *str, t_dataopt *dataopt)
{
	if (*str == '%')
		str++;
	while ((*str) == '-' || *str == '0')
		str++;
	while (ft_isdigit(*str) || *str == '*')
		str++;
	while ((*str) == '-')
		str++;
	if (ispoint(*str, &*dataopt))
		str++;
	while (ft_isdigit(*str) || *str == '*')
		str++;
	if (isparam(*str))
		return (1);
	return (0);
}

int	ft_nbrlen(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_nbrhexalen(long long  n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void inputpad(char cpad, int n)
{
	while (n && n > 0)
	{
		write(1, &cpad, 1);
		n--;
	}
}


int ft_print_d(t_dataopt *dopt, int n)
{
	int nwid;
	int	czero;
	int	lspace;
	int	rspace;
	int	fminus;
	int	mminus;
	
	mminus = 0;
	nwid = ft_nbrlen(n);
	if (dopt->isleft)
	{
		fminus = (n < 0) ? 1 : 0;
		if (dopt->iszero && !dopt->preci )
			czero = dopt->dwidth - nwid + fminus;
		else
			czero = dopt->preci - nwid + fminus;
		rspace = (dopt->dwidth > dopt->preci) ? dopt->dwidth -
			(dopt->preci > nwid ? dopt->preci + fminus : nwid) : 0;
		lspace = 0;
		n = n < 0 ? -n : n;
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			mminus = 1;
			if(dopt->preci)
				dopt->preci++;
		}
			fminus = 0;
		if (dopt->iszero && !dopt->preci)
			czero = dopt->dwidth - nwid;
		else
			czero = dopt->preci - nwid;
		if (czero < 0)
			czero = 0;
		lspace = (dopt->dwidth > czero + nwid) ? dopt->dwidth - nwid - czero : 0;
		rspace = 0;
	}
	inputpad('-', fminus);
	inputpad(' ', lspace);
	inputpad('-', mminus);
	inputpad('0', czero);
	if (!(dopt->ispoint && !dopt->preci))
		ft_putnbr(n);
	else if (dopt->dwidth)
		inputpad(' ', 1);
	inputpad(' ', rspace);
	return (1);
}

int ft_print_c(t_dataopt *dopt, int n)
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
		inputpad(' ', dopt->dwidth -  wid);
		ft_putchar(n);
	}
	else
		ft_putchar(n);
	return (1);
}

int ft_print_s(t_dataopt *dopt, char *s)
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
		return(1);
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
	return (1);
}

int	ft_print_x(t_dataopt *dopt, unsigned int n, int type)
{
	int nwid;
	int	czero;
	int	lspace;
	int	rspace;
	int	fminus;
	int	mminus;
	
	mminus = 0;
	nwid = ft_nbrhexalen(n);
	if (dopt->isleft)
	{
		fminus = (n < 0) ? 1 : 0;
		if (dopt->iszero && !dopt->preci )
			czero = dopt->dwidth - nwid + fminus;
		else
			czero = dopt->preci - nwid + fminus;
		rspace = (dopt->dwidth > dopt->preci) ? dopt->dwidth -
			(dopt->preci > nwid ? dopt->preci + fminus : nwid) : 0;
		lspace = 0;
		n = n < 0 ? -n : n;
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			mminus = 1;
			if(dopt->preci)
				dopt->preci++;
		}
			fminus = 0;
		if (dopt->iszero && !dopt->preci)
			czero = dopt->dwidth - nwid;
		else
			czero = dopt->preci - nwid;
		if (czero < 0)
			czero = 0;
		lspace = (dopt->dwidth > czero + nwid) ? dopt->dwidth - nwid - czero : 0;
		rspace = 0;
	}
	inputpad('-', fminus);
	inputpad(' ', lspace);
	inputpad('-', mminus);
	inputpad('0', czero);
	if (!(dopt->ispoint && !dopt->preci))
		ft_puthexa(n, type, n);
	else if (dopt->dwidth)
		inputpad(' ', 1);
	inputpad(' ', rspace);
	return (1);
}

int ft_print_p(t_dataopt *dopt, long long n)
{
	int nwid;
	int	czero;
	int	lspace;
	int	rspace;
	int	fminus;
	int	mminus;
	
	mminus = 0;
	nwid = ft_nbrhexalen(n) + 2;
	if (dopt->isleft)
	{
		fminus = (n < 0) ? 1 : 0;
		if (dopt->iszero && !dopt->preci )
			czero = dopt->dwidth - nwid + fminus;
		else
			czero = dopt->preci - nwid + fminus;
		rspace = (dopt->dwidth > dopt->preci) ? dopt->dwidth -
			(dopt->preci > nwid ? dopt->preci + fminus : nwid) : 0;
		lspace = 0;
		n = n < 0 ? -n : n;
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			mminus = 1;
			if(dopt->preci)
				dopt->preci++;
		}
			fminus = 0;
		if (dopt->iszero && !dopt->preci)
			czero = dopt->dwidth - nwid;
		else
			czero = dopt->preci - nwid;
		if (czero < 0)
			czero = 0;
		lspace = (dopt->dwidth > czero + nwid) ? dopt->dwidth - nwid - czero : 0;
		rspace = 0;
	}
	inputpad('-', fminus);
	inputpad(' ', lspace);
	inputpad('-', mminus);
//	printf("'czero : %d'", czero);
	inputpad('0', czero);
	if (!(dopt->ispoint && !dopt->preci))
		ft_putpointer(n);
	else if (dopt->dwidth)
	{
		inputpad('0', 1);
		inputpad('x', 1);
	}
	inputpad(' ', rspace);
	return (1);
}

int ft_print_u(t_dataopt *dopt, unsigned int n)
{
	int nwid;
	int	czero;
	int	lspace;
	int	rspace;
	int	fminus;
	int	mminus;
	
	mminus = 0;
	nwid = ft_nbrlen(n);
	if (dopt->isleft)
	{
		fminus = (n < 0) ? 1 : 0;
		if (dopt->iszero && !dopt->preci )
			czero = dopt->dwidth - nwid + fminus;
		else
			czero = dopt->preci - nwid + fminus;
		rspace = (dopt->dwidth > dopt->preci) ? dopt->dwidth -
			(dopt->preci > nwid ? dopt->preci + fminus : nwid) : 0;
		lspace = 0;
		n = n < 0 ? -n : n;
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			mminus = 1;
			if(dopt->preci)
				dopt->preci++;
		}
			fminus = 0;
		if (dopt->iszero && !dopt->preci)
			czero = dopt->dwidth - nwid;
		else
			czero = dopt->preci - nwid;
		if (czero < 0)
			czero = 0;
		lspace = (dopt->dwidth > czero + nwid) ? dopt->dwidth - nwid - czero : 0;
		rspace = 0;
	}
	inputpad('-', fminus);
	inputpad(' ', lspace);
	inputpad('-', mminus);
	inputpad('0', czero);
	if (!(dopt->ispoint && !dopt->preci))
		ft_putunbr(n);
	else if (dopt->dwidth)
		inputpad(' ', 1);
	inputpad(' ', rspace);
	return (1);
}

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
	return (1);


}

int	ft_printf(const char *types, ...)
{
	char		*str;
	t_dataopt	dataopt;
	int			i;

	i = 0;
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
			if (*str == 'd' || *str == 'i')
				ft_print_d(&dataopt, va_arg(dataopt.valist, int));
			if (*str == 'c')
				ft_print_c(&dataopt, va_arg(dataopt.valist, int));
			if (*str == 's')
				ft_print_s(&dataopt, va_arg(dataopt.valist, char *));
			if (*str == 'X')
				ft_print_x(&dataopt, va_arg(dataopt.valist, int), 1);
			if (*str == 'x')
				ft_print_x(&dataopt, va_arg(dataopt.valist, int), 2);
			if (*str == 'p')
				ft_print_p(&dataopt, (long long)va_arg(dataopt.valist, void *));
			if (*str == 'u')
				ft_print_u(&dataopt, (unsigned int)va_arg(dataopt.valist, int));
			if (*str == '%')
				ft_print_percent(&dataopt);
		}
		else
			write(1, str, 1);
		str++;
	}
	va_end(dataopt.valist);
	return (0);
}

