/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:56:09 by hekang            #+#    #+#             */
/*   Updated: 2020/11/10 17:44:34 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(int un, int c)
{
	unsigned int	n;

	n = un;
	if (n > 0)
	{
		ft_puthexa(n / 16, c);
		if (c == 1)
			write(1, &"0123456789ABCDEF"[n % 16], 1);
		else
			write(1, &"0123456789abcdef"[n % 16], 1);
	}
}

void	ft_printpointer(long long p)
{
	if (p == 0)
		write(1, "0", 1);
	else if (p > 0)
	{
		ft_printpointer(p / 16);
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
	ft_printpointer(ll);
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

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putnbr(-214748364);
		ft_putchar('8');
	}
	else if (n < 0)
	{
		ft_putchar('-');
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
