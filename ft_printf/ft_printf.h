/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:00:03 by hekang            #+#    #+#             */
/*   Updated: 2020/11/19 19:57:35 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef	struct	s_dataopt
{
	int		dwidth;
	int		isleft;
	int		iszero;
	int		preci;
	int		ispoint;
	va_list	valist;
}				t_dataopt;

void	ft_puthexa(unsigned int n, int c, int zero);
void	ft_putstr(char *s);
void	ft_putnstr(char *s, int c);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putunbr(int un);
void	ft_putpointer(long long ull);
int		check_digit(const char *str);
int		ft_printf(const char *types, ...);
//int		ft_atoi(const char *str);

#endif
