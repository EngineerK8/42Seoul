/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:41:27 by hekang            #+#    #+#             */
/*   Updated: 2020/10/02 20:49:20 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			cnt;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	cnt = 0;

	while(cnt < n - 1)
	{
		if (us1[cnt] != us2[cnt])
			return (us1[cnt] - us2[cnt]);
		cnt++;
	}
	return (0);
}
