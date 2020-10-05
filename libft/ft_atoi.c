/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 22:40:21 by hekang            #+#    #+#             */
/*   Updated: 2020/10/02 23:01:46 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					cnt;
	unsigned long int	result;
	int					minus;

	cnt = 0;
	minus = 1;
	result = 0;
	while (str[cnt] == ' ' || str[cnt] == '\t' || str[cnt] == '\n'
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
