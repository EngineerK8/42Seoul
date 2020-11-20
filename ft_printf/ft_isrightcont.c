/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrightcont.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:08:37 by hekang            #+#    #+#             */
/*   Updated: 2020/11/20 11:14:32 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isrightcont(char *str, t_dataopt *dataopt)
{
	if (*str == '%')
		str++;
	while ((*str) == '-' || *str == '0')
		str++;
	while (ft_isdigit(*str) || *str == '*')
		str++;
	while ((*str) == '-')
		str++;
	if (ispoint(*str, &*dataopt))
		str++;
	while (ft_isdigit(*str) || *str == '*')
		str++;
	if (isparam(*str))
		return (1);
	return (0);
}
