/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 19:47:11 by hekang            #+#    #+#             */
/*   Updated: 2020/10/05 22:50:00 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
		const void *restrict src, int c, size_t n)
{
	size_t			cnt;
	unsigned char	*usrc;
	int				flag;

	cnt = 0;
	usrc = (unsigned char *)src;
	flag = 0;
	while (cnt < n && !flag && usrc[cnt])
	{
		if (usrc[cnt] == c)
			flag = 1;
		cnt++;
	}
	if (flag == 1)
	{
		ft_memcpy(dst, src, cnt);
		return (dst + cnt);
	}
	else
	{
		ft_memcpy(dst, src, n);
		return (0);
	}
}
