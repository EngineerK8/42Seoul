/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:55:50 by hekang            #+#    #+#             */
/*   Updated: 2020/11/20 16:42:10 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	iszero(char c)
{
	if (c == '0')
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
