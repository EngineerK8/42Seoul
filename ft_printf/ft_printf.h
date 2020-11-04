/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:00:03 by hekang            #+#    #+#             */
/*   Updated: 2020/11/04 14:09:27 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_data
{
	int		type;
	int		value;
	int		sign;
	int		width;
	int		flags;
	int		preci;
	int		size;
	va_list	valist;
}				t_data;

void	ft_puthexa(int n, int c);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putunbr(int un);
void	ft_putpointer(long long ull);
int		check_digit(const char *str);
int		ft_atoi(const char *str);

#endif
