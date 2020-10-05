/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 22:05:16 by hekang            #+#    #+#             */
/*   Updated: 2020/10/02 22:13:19 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cnt;

	cnt = 0;
	while (s[cnt])
	{
		if (s[cnt] == c)
			return (s + cnt);
		cnt++;
	}
	return (NULL);
}
