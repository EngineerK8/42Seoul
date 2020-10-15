/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:12:27 by hekang            #+#    #+#             */
/*   Updated: 2020/10/15 10:45:59 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < len)
	{
		((unsigned char *)b)[cnt] = c;
		cnt++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = (void *)malloc(count * size);
	if (str == 0)
		return (0);
	ft_memset(str, 0, count * size);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t cnt;

	if (dst == 0 && src == 0)
		return (dst);
	cnt = 0;
	while (cnt < n)
	{
		((unsigned char *)dst)[cnt] = ((unsigned char *)src)[cnt];
		cnt++;
	}
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	str = ft_calloc(len + 1, 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len);
	str[len] = 0;
	return (str);
}
