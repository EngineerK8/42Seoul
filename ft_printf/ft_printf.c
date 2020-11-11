/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:56:36 by hekang            #+#    #+#             */
/*   Updated: 2020/11/11 18:46:49 by hekang           ###   ########.fr       */
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
	return (1);
}

int	isparam(char c)
{
	if (c == 'd' || c == 'c' || c == 's' || c == 'X' ||
			c == 'x' || c == 'p' || c == 'u')
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

int	ispoint(char c)
{
	if (c == '.')
		return (1);
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
	if (!ispoint(**str))
		return ;
	(*str)++;
	while (ft_isdigit(**str))
	{
		dataopt->preci = dataopt->preci * 10 + **str - '0';
		(*str)++;
	}
}


int	isrightcont(char *str)
{
	if (*str == '%')
		str++;
	while ((*str) == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (ispoint(*str))
		str++;
	while (ft_isdigit(*str))
		str++;
	while (isparam(*str))
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

int	ft_nbrhexalen(int n)
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
	int wid;
	int	czero;
	int	lspace;
	int	rspace;

	wid = ft_nbrlen(n);
	czero = (dopt->preci > wid) ? dopt->preci - wid : 0;



	if (dopt->isleft)
	{
		if (n < 0 && (dopt->iszero || dopt->preci > wid))
		{
			write(1, "-", 1);
			n = -n;
			dopt->preci++;
		}
		if (dopt->preci > wid)
			inputpad('0', dopt->preci - wid);
		ft_putnbr(n);
		inputpad(' ', dopt->dwidth - (dopt->preci > wid ? dopt->preci : wid));
	}
	else
	{
		if (n < 0 && dopt->preci > wid)
			dopt->preci++;
		if (!dopt->iszero)
			inputpad(' ', dopt->dwidth - (dopt->preci > wid ? dopt->preci : wid));
		if (n < 0 && (dopt->iszero || dopt->preci > wid))
		{
			write(1, "-", 1);
			n = -n;
		}	
		if (dopt->iszero)
		{
			if (dopt->preci && dopt->dwidth > dopt->preci)
			{
				inputpad(' ', dopt->dwidth - dopt->preci);
				inputpad('0', dopt->preci > wid ? dopt->preci : wid);
			}
			else
				inputpad('0', dopt->preci > wid ? dopt->preci : wid);
		}
		if (dopt->preci > wid)
			inputpad('0', dopt->preci - wid);
		ft_putnbr(n);
	}
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

	wid = ft_strlen(s);
	if (dopt->isleft)
	{
		ft_putstr(s);
		inputpad(' ', dopt->dwidth - wid);
	}
	else if (dopt->dwidth > (dopt->preci < wid ? dopt->preci : wid))
	{
		inputpad(' ', dopt->dwidth - wid);
		s[dopt->preci] = 0;
		ft_putstr(s);
	}
	else
		ft_putstr(s);
	return (1);
}

int	ft_print_x(t_dataopt *dopt, int n, int type)
{
	int	wid;

	wid = ft_nbrhexalen(n);
	if (dopt->isleft)
	{
		ft_puthexa(n, type);
		inputpad(' ', dopt->dwidth - wid);
	}
	else if (dopt->dwidth > wid)
	{
		inputpad(' ', dopt->dwidth - (dopt->preci > wid ? dopt->preci : wid));
		if (dopt->preci > wid)
			inputpad('0', dopt->preci - wid);
		ft_puthexa(n, type);
	}
	else
		ft_puthexa(n, type);
	return (1);
}

int ft_print_p(t_dataopt *dopt, long long n)
{
	int wid;

	wid = 14;
	if (dopt->isleft)
	{
		ft_putpointer(n);
		inputpad(' ', dopt->dwidth - wid);
	}
	else if (dopt->dwidth > wid)
	{
		inputpad(' ', dopt->dwidth - (dopt->preci > wid ? dopt->preci : wid));
		if (dopt->preci > wid)
			inputpad('0', dopt->preci - wid);
		ft_putpointer(n);
	}
	else
		ft_putpointer(n);
	return (1);
}
int ft_print_u(t_dataopt *dopt, int n)
{
	int wid;

	wid = ft_nbrlen(n);
	if (dopt->isleft)
	{
		ft_putunbr(n);
		inputpad(' ', dopt->dwidth - wid);
	}
	else if (dopt->dwidth > wid)
	{
		inputpad(' ', dopt->dwidth - (dopt->preci > wid ? dopt->preci : wid));
		if (dopt->preci > wid)
			inputpad('0', dopt->preci - wid);
		ft_putunbr(n);
	}
	else
		ft_putunbr(n);
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
		if (*(str + 1) && *str == '%' && isrightcont(str))
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
				ft_print_u(&dataopt, va_arg(dataopt.valist, int));
		}
		else
			write(1, str, 1);
		str++;
	}
	va_end(dataopt.valist);
	return (0);
}

