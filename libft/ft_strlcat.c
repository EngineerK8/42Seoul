/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:32:08 by hekang            #+#    #+#             */
/*   Updated: 2020/10/02 22:04:49 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src,
		size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j] && i + j + 1 < dstsize)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	while (src[j])
		j++;
	if (i > dstsize)
		return (dstsize + j);
	else
		return (i + j);
}
