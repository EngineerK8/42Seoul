/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:56:09 by hekang            #+#    #+#             */
/*   Updated: 2020/11/03 16:06:47 by hekang           ###   ########.fr       */
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
	if (p > 0)
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

int	check_digit(const char *str)
{
	int	cnt;
	int	i;
	int	minus;

	cnt = 0;
	i = 0;
	minus = 1;
	while (str[cnt] == ' ' || str[cnt] == '\t' || str[cnt] == '\n' ||
			str[cnt] == '\v' || str[cnt] == '\f' || str[cnt] == '\r')
		cnt++;
	if (str[cnt] == '+' || str[cnt] == '-')
	{
		if (str[cnt] == '-')
			minus = -1;
		cnt++;
	}
	while (str[cnt + i])
	{
		if (str[cnt + i] >= '0' && str[cnt + i] <= '9')
			i++;
		else
			break ;
	}
	return (i * minus);
}

int	ft_atoi(const char *str)
{
	int					cnt;
	unsigned long int	result;
	int					minus;

	if (check_digit(str) >= 20 || check_digit(str) <= -20)
		return (check_digit(str) > 0 ? -1 : 0);
	cnt = 0;
	minus = 1;
	result = 0;
	while (str[cnt] == ' ' || str[cnt] == '\t' || str[cnt] == '\n' ||
			str[cnt] == '\v' || str[cnt] == '\f' || str[cnt] == '\r')
		cnt++;
	if (str[cnt] == '+' || str[cnt] == '-')
	{
		if (str[cnt] == '-')
			minus = -1;
		cnt++;
	}
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		result = result * 10 + str[cnt] - '0';
		cnt++;
	}
	return (result * minus);
}
