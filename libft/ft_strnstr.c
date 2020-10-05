/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 22:16:11 by hekang            #+#    #+#             */
/*   Updated: 2020/10/02 22:29:52 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cnt;
	size_t	cnt2;

	cnt = 0;
	cnt2 = 0;
	while (cnt < len)
	{
		cnt2 = 0;
		if (haystack[cnt] == needle[cnt2])
		{
			while (needle[cnt2])
			{
				if (haystack[cnt + cnt2] != needle[cnt2])
					break ;
				cnt2++;
				if (needle[cnt2] == '\0')
					return (haystack + cnt);
			}
		}
		cnt++;
	}
	return (NULL);
}
