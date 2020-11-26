/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2nd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:00:54 by hekang            #+#    #+#             */
/*   Updated: 2020/11/25 11:01:47 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
