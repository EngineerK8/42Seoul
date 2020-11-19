/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:56:09 by hekang            #+#    #+#             */
/*   Updated: 2020/11/19 21:00:03 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int un, int c, int iszero)
{
	if (un == 0 && iszero == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (un > 0)
	{
		ft_puthexa(un / 16, c, iszero);
		if (c == 1)
			write(1, &"0123456789ABCDEF"[un % 16], 1);
		else
			write(1, &"0123456789abcdef"[un % 16], 1);
	}
}

void	ft_printpointer(long long p, long long pp)
{
	if (p == 0 && pp == 0)
		write(1, "0", 1);
	if (p > 0)
	{
		ft_printpointer(p / 16, pp);
		write(1, &"0123456789abcdef"[p % 16], 1);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putpointer(long long ll)
{
	ft_putstr("0x");
	ft_printpointer(ll, ll);
}

void	ft_putstr(char *s)
{
	int	cnt;

	if (s == 0)
		return ;
	cnt = 0;
	while (s[cnt])
	{
		write(1, &s[cnt], 1);
		cnt++;
	}
}

void	ft_putnstr(char *s, int c)
{
	int	cnt;

	if (s == 0)
		return ;
	cnt = 0;
	while (cnt < c)
	{
		write(1, &s[cnt], 1);
		cnt++;
	}
}
void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putnbr(214748364);
		ft_putchar('8');
	}
	else if (n < 0)
	{
		ft_putnbr(-n);
	}
	else
	{
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void	ft_putunbr(int un)
{
	unsigned int n;

	n = un;
	
	if (n >= 10)
		ft_putunbr(n / 10);
	ft_putchar(n % 10 + '0');
}
