/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:00:03 by hekang            #+#    #+#             */
/*   Updated: 2020/11/20 16:36:53 by hekang           ###   ########.fr       */
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
	int			dwidth;
	int			isleft;
	int			iszero;
	int			preci;
	int			ispoint;
	va_list		valist;
	int			czero;
	int			lspace;
	int			rspace;
	int			fminus;
	int			mminus;
	int			rvalue;
}				t_dataopt;

void			ft_puthexa(unsigned int n, int c, int zero);
void			ft_putstr(char *s);
void			ft_putnstr(char *s, int c);
void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_putunbr(int un);
void			ft_putpointer(long long ull);
int				check_digit(const char *str);
int				ft_printf(const char *types, ...);
int				isparam(char c);
int				isminus(char c);
int				iszero(char c);
int				ispoint(char c, t_dataopt *dataopt);
int				isstar(char c);
void			checkflag(char **str, t_dataopt *dataopt);
void			checkwidth(char **str, t_dataopt *dataopt);
void			checkprecision(char **str, t_dataopt *dataopt);
int				ft_nbrlen(int n);
int				ft_nbrhexalen(long long n);
int				isrightcont(char *str, t_dataopt *dataopt);
long long		ft_calc_print(t_dataopt *dopt, long long n, int nwid);
int				ft_print_d(t_dataopt *dopt, int n);
int				ft_print_c(t_dataopt *dopt, int n);
int				ft_print_s(t_dataopt *dopt, char *s);
int				ft_print_x(t_dataopt *dopt, unsigned int n, int type);
int				ft_print_p(t_dataopt *dopt, long long n);
int				ft_print_u(t_dataopt *dopt, unsigned int n);
int				ft_print_percent(t_dataopt *dopt);
void			inputpad(char cpad, int n);

#endif
