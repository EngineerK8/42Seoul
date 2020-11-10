/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:00:03 by hekang            #+#    #+#             */
/*   Updated: 2020/11/10 18:16:27 by hekang           ###   ########.fr       */
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
	va_list	valist;
}				t_dataopt;

void	ft_puthexa(int n, int c);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putunbr(int un);
void	ft_putpointer(long long ull);
int		check_digit(const char *str);
//int		ft_atoi(const char *str);

#endif
