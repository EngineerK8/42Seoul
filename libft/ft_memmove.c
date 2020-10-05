/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:13:31 by hekang            #+#    #+#             */
/*   Updated: 2020/10/02 20:23:08 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;
	unsigned char	temp[len];

	if (dst == NULL || src == NULL)
		return (NULL);
	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	memcpy(temp, usrc, len);
	memcpy(usrc, udst, len);
	return (dst);
}
